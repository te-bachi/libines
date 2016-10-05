#ifndef __CHARACTER_HXX__
#define __CHARACTER_HXX__

#include "jam/Global.hxx"
#include "jam/lang/Object.hxx"

namespace jam {
    namespace lang {
        
        class CharacterImpl;
        
        class Character : public Object {
            public:
                const static Class klass;
                
                typedef enum {
                    UNKNOW = 0,
                    UPPER_CASE,
                    LOWER_CASE,
                    DIGIT,
                    SPECIAL
                } Category;
                
                const static char HEXADECIMAL_LOWER[17];
                const static char HEXADECIMAL_UPPER[17];
                
            public:
                Character();
                Character(const Reference& ref);
                Character(Implementation* impl);
                virtual ~Character();
                CharacterImpl& operator*();
                CharacterImpl* operator->();
                const Character& operator=(const Reference& ref);
                const Character& operator=(Implementation* impl);
                
                static Character newInstance();
                static char* initialize(char filler, int length);
                static int length(const char* chr);
                static int digit(char chr);
                static char toUpperCase(char chr);
                static char toLowerCase(char chr);
                static boolean isDigit(char chr);
                static boolean isLetter(char chr);
                static boolean isLowerCase(char chr);
                static boolean isUpperCase(char chr);
                static boolean isWhitespace(char chr);
                static boolean isSpecialCharacter(char chr);
                static int analyze(char chr);
        };
        
        class CharacterImpl : public ObjectImpl {
            public:
                
            private:
                
            public:
                CharacterImpl();
                virtual ~CharacterImpl();
                
                #ifdef __DEBUG__
                virtual const char* debugClassName();
                #endif
                
                virtual Object clone();
                virtual String toString();
                virtual Class getClass();
                
            private:
                CharacterImpl(const CharacterImpl& copy);
        };
    }
}

#endif
