#include "jam/lang/Exception.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/StringBuffer.hxx"
#include "jam/util/ArrayList.hxx"
#include "jam/util/Iterator.hxx"
#include "jam/lang/StackTraceElement.hxx"
#include "jam/lang/RegisterElement.hxx"

#include <ucontext.h>
#include <dlfcn.h>

#if defined(__sparc) || defined(__sparc__)
#include <demangle.h>
#include <sys/frame.h>
#elif defined(__i386__) && defined(__FreeBSD__)
struct frame {
    struct frame*   fr_savfp;
    int             fr_savpc;
};
#elif __WORDSIZE == 64 && defined (__linux__)
#include <cxxabi.h>
#include <string.h>
struct frame {
    struct frame* fr_savfp;
    greg_t fr_savpc;
};
#endif

using namespace jam::lang;

const Class Exception::klass = Class::newInstance("jam::lang::Exception");

/*** Reference ***/

Exception::Exception() : Object() {
    //
}

Exception::Exception(const Reference& ref) : Object(ref) {
    //
}

Exception::Exception(Implementation* impl) : Object(impl) {
    //
}

Exception::~Exception() {
    //
}

ExceptionImpl& Exception::operator*() {
    return (ExceptionImpl&) Object::operator*();
}

ExceptionImpl* Exception::operator->() {
    return (ExceptionImpl*) Object::operator->();
}

const Exception& Exception::operator=(const Reference& ref) {
    return (Exception&) Object::operator=(ref);
}

const Exception& Exception::operator=(Implementation* impl) {
    return (Exception&) Object::operator=(impl);
}

Exception Exception::newInstance() {
    return Exception(new ExceptionImpl());
}

Exception Exception::newInstance(String message) {
    return Exception(new ExceptionImpl(message));
}

Exception Exception::newInstance(Exception cause) {
    return Exception(new ExceptionImpl(cause));
}

Exception Exception::newInstance(String message, Exception cause) {
    return Exception(new ExceptionImpl(message, cause));
}

/*** Implementation ***/

ExceptionImpl::ExceptionImpl() {
    init((StringImpl *) null, (ExceptionImpl *) null);
}

ExceptionImpl::ExceptionImpl(String message) {
    init(message, (ExceptionImpl *) null);
}

ExceptionImpl::ExceptionImpl(Exception cause) {
    init((StringImpl *) null, cause);
}

ExceptionImpl::ExceptionImpl(String message, Exception cause) {
    init(message, cause);
}

ExceptionImpl::~ExceptionImpl() {
    
}

ExceptionImpl::ExceptionImpl(const ExceptionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ExceptionImpl::debugClassName() {
    return "jam::lang::Exception";
}
#endif

String ExceptionImpl::toString() {
    return null;
}

Class ExceptionImpl::getClass() {
    return Exception::klass;
}

void ExceptionImpl::init(String message, Exception cause) {
    ucontext_t      ctx;        // user thread context
    struct frame*   frame;      // stack frame
    Dl_info         info;       // symbol
    String          library;
    String          function;
#if defined(__sparc) || defined(__sparc__)
    char            buffer[1024];
#endif
    
    _message          = message;
    _cause            = cause;
    _maxLibraryLength = 0;
    _stackTraceList   = ArrayList::newInstance();
    _registerList     = ArrayList::newInstance(18);
    
    getcontext(&ctx);
    
#if defined(__sparc) || defined(__sparc__)
    frame = (struct frame*) ctx.uc_mcontext.gregs[REG_SP];
#elif defined(__i386__) && defined(__FreeBSD__)
    frame = (struct frame*) ctx.uc_mcontext.mc_ebp;
#elif __WORDSIZE == 64 && defined (__linux__)
    frame = (struct frame*) ctx.uc_mcontext.gregs[REG_RBP];
#endif
    
    // walk through stack
    while (frame && frame->fr_savfp) {
        if (dladdr((void *) frame->fr_savpc, &info) == 0) {
            function = "???";
            library  = "???";
        } else {
#if defined(__sparc) || defined(__sparc__)
            cplus_demangle(info.dli_sname, buffer, sizeof(buffer));
            function = buffer;
#elif defined(__i386__) && defined(__FreeBSD__)
            function = info.dli_sname; // cplus_demangle(info.dli_sname, DMGL_PARAMS | DMGL_ANSI | DMGL_VERBOSE | DMGL_TYPES);
#elif __WORDSIZE == 64 && defined (__linux__)
            if (strlen(info.dli_sname) > 2 && info.dli_sname[0] == '_' && info.dli_sname[1] == 'Z') {
                int status;
                function = __cxxabiv1::__cxa_demangle(info.dli_sname, 0, 0, &status);
            } else {
                function = info.dli_sname;
            }
#endif
            library  = info.dli_fname;
        }
        if (library->length() > _maxLibraryLength) {
            _maxLibraryLength = library->length();
        }
        _stackTraceList->add(StackTraceElement::newInstance(library, frame->fr_savpc, function, (unsigned long int) info.dli_saddr));
        frame = frame->fr_savfp;
    }
    
    // save registers
#if defined(__sparc) || defined(__sparc__)
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_PC"), ctx.uc_mcontext.gregs[REG_PC]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_NC"), ctx.uc_mcontext.gregs[REG_nPC]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_SP"), ctx.uc_mcontext.gregs[REG_SP]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_O0"), ctx.uc_mcontext.gregs[REG_O0]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_O1"), ctx.uc_mcontext.gregs[REG_O1]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_O2"), ctx.uc_mcontext.gregs[REG_O2]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_O3"), ctx.uc_mcontext.gregs[REG_O3]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_O4"), ctx.uc_mcontext.gregs[REG_O4]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_O5"), ctx.uc_mcontext.gregs[REG_O5]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_O6"), ctx.uc_mcontext.gregs[REG_O6]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_O7"), ctx.uc_mcontext.gregs[REG_O7]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_G1"), ctx.uc_mcontext.gregs[REG_G1]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_G2"), ctx.uc_mcontext.gregs[REG_G2]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_G3"), ctx.uc_mcontext.gregs[REG_G3]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_G4"), ctx.uc_mcontext.gregs[REG_G4]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_G5"), ctx.uc_mcontext.gregs[REG_G5]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_G6"), ctx.uc_mcontext.gregs[REG_G6]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("REG_G7"), ctx.uc_mcontext.gregs[REG_G7]));
#elif defined(__i386__) && defined(__FreeBSD__)
    _registerList->add(RegisterElement::newInstance(String::newInstance("EAX"), ctx.uc_mcontext.mc_eax));
    _registerList->add(RegisterElement::newInstance(String::newInstance("EBX"), ctx.uc_mcontext.mc_ebx));
    _registerList->add(RegisterElement::newInstance(String::newInstance("ECX"), ctx.uc_mcontext.mc_ecx));
    _registerList->add(RegisterElement::newInstance(String::newInstance("EDX"), ctx.uc_mcontext.mc_edx));
    _registerList->add(RegisterElement::newInstance(String::newInstance("ESI"), ctx.uc_mcontext.mc_esi));
    _registerList->add(RegisterElement::newInstance(String::newInstance("EDI"), ctx.uc_mcontext.mc_edi));
    _registerList->add(RegisterElement::newInstance(String::newInstance("EBP"), ctx.uc_mcontext.mc_ebp));
    _registerList->add(RegisterElement::newInstance(String::newInstance("ESP"), ctx.uc_mcontext.mc_esp));
    _registerList->add(RegisterElement::newInstance(String::newInstance("CS"), ctx.uc_mcontext.mc_cs));
    _registerList->add(RegisterElement::newInstance(String::newInstance("DS"), ctx.uc_mcontext.mc_ds));
    _registerList->add(RegisterElement::newInstance(String::newInstance("ES"), ctx.uc_mcontext.mc_es));
    _registerList->add(RegisterElement::newInstance(String::newInstance("FS"), ctx.uc_mcontext.mc_fs));
    _registerList->add(RegisterElement::newInstance(String::newInstance("GS"), ctx.uc_mcontext.mc_gs));
    _registerList->add(RegisterElement::newInstance(String::newInstance("SS"), ctx.uc_mcontext.mc_ss));
    _registerList->add(RegisterElement::newInstance(String::newInstance("EIP"), ctx.uc_mcontext.mc_eip));
    _registerList->add(RegisterElement::newInstance(String::newInstance("EFLAGS"), ctx.uc_mcontext.mc_eflags));
#elif __WORDSIZE == 64 && defined (__linux__)
    _registerList->add(RegisterElement::newInstance(String::newInstance("RAX"), ctx.uc_mcontext.gregs[REG_RAX]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("RBX"), ctx.uc_mcontext.gregs[REG_RBX]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("RCX"), ctx.uc_mcontext.gregs[REG_RCX]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("RDX"), ctx.uc_mcontext.gregs[REG_RDX]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("RBP"), ctx.uc_mcontext.gregs[REG_RBP]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("RSP"), ctx.uc_mcontext.gregs[REG_RSP]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("RSI"), ctx.uc_mcontext.gregs[REG_RSI]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("RDI"), ctx.uc_mcontext.gregs[REG_RDI]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("R8"), ctx.uc_mcontext.gregs[REG_R8]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("R9"), ctx.uc_mcontext.gregs[REG_R9]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("R10"), ctx.uc_mcontext.gregs[REG_R10]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("R11"), ctx.uc_mcontext.gregs[REG_R11]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("R12"), ctx.uc_mcontext.gregs[REG_R12]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("R13"), ctx.uc_mcontext.gregs[REG_R13]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("R14"), ctx.uc_mcontext.gregs[REG_R14]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("R15"), ctx.uc_mcontext.gregs[REG_R15]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("RIP"), ctx.uc_mcontext.gregs[REG_RIP]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("EFL"), ctx.uc_mcontext.gregs[REG_EFL]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("CSGSFS"), ctx.uc_mcontext.gregs[REG_CSGSFS]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("ERR"), ctx.uc_mcontext.gregs[REG_ERR]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("OLDMASK"), ctx.uc_mcontext.gregs[REG_OLDMASK]));
    _registerList->add(RegisterElement::newInstance(String::newInstance("CR2"), ctx.uc_mcontext.gregs[REG_CR2]));
#endif
}
    
String ExceptionImpl::getMessage() {
    return _message;
}

List ExceptionImpl::getStackTrace() {
    return _stackTraceList;
}

String ExceptionImpl::printStackTrace() {
    StringBuffer      buffer;
    StackTraceElement element;
    Iterator          iter;
    int               length;
    
    buffer = StringBuffer::newInstance();
    
    iter = _stackTraceList->iterator();
    while (iter->hasNext()) {
        element = (StackTraceElement) iter->next();
        length  = element->getLibrary()->length();
        buffer->append(element->getLibrary());
        buffer->append(':');
        while (length < _maxLibraryLength) {
            buffer->append(' ');
            length++;
        }
        buffer->append(' ');
        buffer->append(element->getFunction());
        buffer->append('\n');
    }
    
    return buffer->toString();
}

List ExceptionImpl::getRegisters() {
    return _registerList;
}

String ExceptionImpl::printRegisters() {
    StringBuffer    buffer;
    RegisterElement element;
    Iterator        iter;
    int             i;
    
    buffer = StringBuffer::newInstance();
    
    iter = _registerList->iterator();
    for (i = 1; iter->hasNext(); i++) {
        element = (RegisterElement) iter->next();
        buffer->append(element->getRegisterName());
        buffer->append(": ");
        buffer->append(String::valueOf((int) element->getValue(), Number::HEXADECIMAL, true));
        if (i % 3 == 0) {
            buffer->append('\n');
        } else {
            buffer->append("   ");
        }
    }
    
    return buffer->toString();
}

String ExceptionImpl::printFullInfos() {
    StringBuffer    buffer;
    
    buffer = StringBuffer::newInstance();
    
    buffer->append("=== S T A C K   T R A C E ===\n");
    buffer->append(printStackTrace());
    buffer->append("\n=== R E G I S T E R S ===\n");
    buffer->append(printRegisters());
    
    return buffer->toString();
}
