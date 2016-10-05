#ifndef __STRING_BUFFER_HXX__
#define __STRING_BUFFER_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace util {
        using namespace lang;
        
        class StringBufferImpl;
        
        class StringBuffer : public Object {
            public:
                const static Class klass;
                
            public:
                StringBuffer();
                StringBuffer(const Reference& ref);
                StringBuffer(Implementation* impl);
                virtual ~StringBuffer();
                StringBufferImpl& operator*();
                StringBufferImpl* operator->();
                const StringBuffer& operator=(const Reference& ref);
                const StringBuffer& operator=(Implementation* impl);
                
                static StringBuffer newInstance();
                static StringBuffer newInstance(int chunkSize);
        };
        
        class StringBufferImpl : public ObjectImpl {
            public:
                
            private:
                struct Chunk {
                    char*  _data;
                    Chunk* _next;
                    
                    Chunk(int chunkSize);
                };
                
                Chunk*  _start;
                Chunk*  _current;
                int     _length;
                int     _chunkSize;
                int     _remainingChunk;
                
            public:
                StringBufferImpl();
                StringBufferImpl(int chunkSize);
                virtual ~StringBufferImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
                virtual void append(String str);
                virtual void append(const char chr);
                virtual void append(const char* str);
                virtual void append(const char* str, int length);
                virtual void append(int number);
                virtual void append(long number);
                virtual void append(double number, int ndigit);
                
                virtual int length();
                virtual int capacity();
                virtual void flush();
                
            private:
                StringBufferImpl(const StringBufferImpl& copy);
                StringBufferImpl::Chunk* initChunk();
                void init(int chunkSize);
                void freeChunks();
        };
    }
}

#endif
