#include "jam/util/StringBuffer.hxx"
#include "jam/lang/String.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/System.hxx"
#include "jam/lang/Character.hxx"

using namespace jam::lang;
using namespace jam::util;

const Class StringBuffer::klass = Class::newInstance("jam::util::StringBuffer");

/*** Reference ***/

StringBuffer::StringBuffer() : Object() {
    //
}

StringBuffer::StringBuffer(const Reference& ref) : Object(ref) {
    //
}

StringBuffer::StringBuffer(Implementation* impl) : Object(impl) {
    //
}

StringBuffer::~StringBuffer() {
    //
}

StringBufferImpl& StringBuffer::operator*() {
    return (StringBufferImpl&) Object::operator*();
}

StringBufferImpl* StringBuffer::operator->() {
    return (StringBufferImpl*) Object::operator->();
}

const StringBuffer& StringBuffer::operator=(const Reference& ref) {
    return (StringBuffer&) Object::operator=(ref);
}

const StringBuffer& StringBuffer::operator=(Implementation* impl) {
    return (StringBuffer&) Object::operator=(impl);
}

StringBuffer StringBuffer::newInstance() {
    return StringBuffer(new StringBufferImpl());
}

StringBuffer StringBuffer::newInstance(int chunkSize) {
    return StringBuffer(new StringBufferImpl(chunkSize));
}

/*** Implementation ***/

StringBufferImpl::StringBufferImpl() {
    init(20);
}

StringBufferImpl::StringBufferImpl(int chunkSize) {
    init(chunkSize);
}

StringBufferImpl::~StringBufferImpl() {
    freeChunks();
}

StringBufferImpl::StringBufferImpl(const StringBufferImpl& copy) {
    //
}

/*******************************************************************************
 * init
 *
 * First we must guarantee, that the chunk size is set,
 * befor we can create new chunks
 *
 * @param chunkSize
 */
void StringBufferImpl::init(int chunkSize) {
    _length         = 0;
    _chunkSize      = chunkSize;
    
    _start          = initChunk();
    _current        = _start;
}

#ifdef __DEBUG__
const char* StringBufferImpl::debugClassName() {
    return "jam::lang::StringBuffer";
}
#endif

/*******************************************************************************
 * clone
 *
 * @return Object
 */
Object StringBufferImpl::clone() {
    return null;
}

/*******************************************************************************
 * toString
 *
 * @return String
 */
String StringBufferImpl::toString() {
    Chunk* chunk;
    char*  chr;
    int    i;
    int    k;
    
    chunk = _start;
    chr   = new char[_length + 1];
    
    for (i = 0; i < _length && chunk != 0;) {
        // IF counter is more than the size of the chunk
        // OR the next chunk is null AND the counter is more than 
        // the length of filled characters, then DON'T loop trough!
        for (k = 0; k < _chunkSize && (chunk->_next != 0 || k < (_chunkSize - _remainingChunk)); k++, i++) {
            chr[i] = chunk->_data[k];
        }
        
        chunk = chunk->_next;
    }
    
    chr[i] = '\0';
    
    return String(new StringImpl(chr, _length + 1, false));
}

/*******************************************************************************
 * getClass
 *
 * @return Class
 */
Class StringBufferImpl::getClass() {
    return StringBuffer::klass;
}

/*******************************************************************************
 * Chunk Constructor
 *
 * @param chunkSize
 */
StringBufferImpl::Chunk::Chunk(int chunkSize) {
    _data = new char[chunkSize];
    _next = 0;
}

/*******************************************************************************
 * initChunk
 *
 * @return Chunk
 */
StringBufferImpl::Chunk* StringBufferImpl::initChunk() {
    Chunk* chunk;
    
    chunk           = new Chunk(_chunkSize);
    _remainingChunk = _chunkSize;
    
    return chunk;
}

/*******************************************************************************
 * append
 *
 * @param str
 */
void StringBufferImpl::append(String str) {
    if (str != null) {
        append(str->toChar(), str->length());
    } else {
        append("null");
    }
}

/*******************************************************************************
 * append
 *
 * @param chr
 */
void StringBufferImpl::append(const char chr) {
    append((const char*) &chr, 1);
}

/*******************************************************************************
 * append
 *
 * @param str
 */
void StringBufferImpl::append(const char* str) {
    append(str, Character::length(str));
}

/*******************************************************************************
 * append
 *
 * @param str
 * @param length
 */
void StringBufferImpl::append(const char* str, int length) {
    char* srcPtr;
    char* destPtr;
    int   remainingCharacters;
    
    srcPtr              = 0;
    destPtr             = 0;
    remainingCharacters = length;
    
    while (remainingCharacters > 0 && _remainingChunk < remainingCharacters) {
        // fill remaining chunk with chars
        srcPtr               = &(((char *)str)[length - remainingCharacters]);
        destPtr              = &(_current->_data[_chunkSize - _remainingChunk]);
        _length             += _remainingChunk;
        remainingCharacters -= _remainingChunk;
        System::memoryCopy(srcPtr, destPtr, _remainingChunk);
        
        // allocate new chunk
        _current->_next = initChunk();
        _current        = _current->_next;
    }
    
    // last chunk filling
    srcPtr           = &(((char *)str)[length - remainingCharacters]);
    destPtr          = &(_current->_data[_chunkSize - _remainingChunk]);
    _length         += remainingCharacters;
    _remainingChunk -= remainingCharacters;
    System::memoryCopy(srcPtr, destPtr, remainingCharacters);
}

void StringBufferImpl::append(int number) {
    append(String::valueOf(number));
}

void StringBufferImpl::append(long number) {
    append(String::valueOf(number));
}

void StringBufferImpl::append(double number, int ndigit) {
    append(String::valueOf(number, ndigit));
}

/*******************************************************************************
 * length
 *
 * @return length
 */
int StringBufferImpl::length() {
    return _length;
}

/*******************************************************************************
 * capacity
 *
 * @return capacity
 */
int StringBufferImpl::capacity() {
    return (_length + _remainingChunk);
}

/*******************************************************************************
 * flush
 */
void StringBufferImpl::flush() {
    freeChunks();
    
    _start   = initChunk();
    _current = _start;
}

/*******************************************************************************
 * freeChunks
 */
void StringBufferImpl::freeChunks() {
    Chunk* previous;
    Chunk* chunk;
    
    for (chunk = _start; chunk->_next != 0; chunk = _start) {
        while (chunk->_next != 0) {
            previous = chunk;
            chunk    = chunk->_next;
        }
        
        delete[] chunk->_data;
        delete chunk;
        
        previous->_next = 0;
    }
    
    delete[] chunk->_data;
    delete   chunk;
    
    _start   = 0;
    _current = 0;
    _length  = 0;
}
