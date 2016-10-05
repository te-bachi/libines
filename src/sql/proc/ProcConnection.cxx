
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[45];
};
static const struct sqlcxp sqlfpn =
{
    44,
    "../../../../src/sql/proc/ProcConnection.pcxx"
};


static unsigned int sqlctx = 1098950516;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned int *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(char *, int *); }

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4128,31,27,0,
5,0,0,1,0,0,27,79,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,10,0,0,1,10,0,0,
36,0,0,2,0,0,29,98,0,0,0,0,0,1,0,
51,0,0,3,0,0,31,103,0,0,0,0,0,1,0,
66,0,0,0,0,0,90,126,0,80,0,0,2,105,110,1,0,
83,0,0,0,0,0,90,127,0,80,0,0,3,111,117,116,1,0,
101,0,0,4,0,0,17,128,0,0,1,1,0,1,0,1,97,0,0,
};


#include "jam/sql/proc/ProcConnection.hxx"
#include "jam/sql/proc/ProcStatement.hxx"
#include "jam/sql/SQLException.hxx"
#include "jam/sql/SQLNotFoundException.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

#include <sqlcpr.h>

using namespace jam::sql;
using namespace jam::sql::proc;
using namespace jam::lang;

const Class ProcConnection::klass = Class::newInstance("jam::sql::proc::ProcConnection");

static void throwException(int sqlcode, const char* message, unsigned short length) {
    throw SQLException::newInstance(sqlcode, String::newInstance(message, length));
}

static void throwNotFoundException(int sqlcode, const char* message, unsigned short length) {
    throw SQLNotFoundException::newInstance(sqlcode, String::newInstance(message, length));
}

/*** Reference ***/

ProcConnection::ProcConnection() : Connection() {
    //
}

ProcConnection::ProcConnection(const Reference& ref) : Connection(ref) {
    //
}

ProcConnection::ProcConnection(Implementation* impl) : Connection(impl) {
    //
}

ProcConnection::~ProcConnection() {
    //
}

ProcConnectionImpl& ProcConnection::operator*() {
    return (ProcConnectionImpl&) Connection::operator*();
}

ProcConnectionImpl* ProcConnection::operator->() {
    return (ProcConnectionImpl*) Connection::operator->();
}

const ProcConnection& ProcConnection::operator=(const Reference& ref) {
    return (ProcConnection&) Connection::operator=(ref);
}

const ProcConnection& ProcConnection::operator=(Implementation* impl) {
    return (ProcConnection&) Connection::operator=(impl);
}

ProcConnection ProcConnection::newInstance(String username, String password) {
    return ProcConnection(new ProcConnectionImpl(username, password));
}

/*** Implementation ***/

ProcConnectionImpl::ProcConnectionImpl() {
    //
}

ProcConnectionImpl::ProcConnectionImpl(String username, String password) {
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        const char* proc_username;
        const char* proc_password;
    /* EXEC SQL END DECLARE SECTION; */ 

    
    proc_username = username->toChar();
    proc_password = password->toChar();
    
    /* EXEC SQL WHENEVER SQLERROR DO throwException(sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc, sqlca.sqlerrm.sqlerrml); */ 

    /* EXEC SQL CONNECT :proc_username IDENTIFIED BY :proc_password; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)proc_username;
    sqlstm.sqhstl[0] = (unsigned long )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)proc_password;
    sqlstm.sqhstl[1] = (unsigned long )0;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) throwException((sqlca.sqlcode),((sqlca.sqlerrm).sqlerrmc),((sqlca.sqlerrm).sqlerrml));
}


}

ProcConnectionImpl::~ProcConnectionImpl() {
    //
}

ProcConnectionImpl::ProcConnectionImpl(const ProcConnectionImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ProcConnectionImpl::debugClassName() {
    return "jam::sql::proc::ProcConnection";
}
#endif

void ProcConnectionImpl::commit() {
    /* EXEC SQL WHENEVER SQLERROR DO throwException(sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc, sqlca.sqlerrm.sqlerrml); */ 

    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )36;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) throwException((sqlca.sqlcode),((sqlca.sqlerrm).sqlerrmc),((sqlca.sqlerrm).sqlerrml));
}


}

void ProcConnectionImpl::rollback() {
    /* EXEC SQL WHENEVER SQLERROR DO throwException(sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc, sqlca.sqlerrm.sqlerrml); */ 

    /* EXEC SQL ROLLBACK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )51;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) throwException((sqlca.sqlcode),((sqlca.sqlerrm).sqlerrmc),((sqlca.sqlerrm).sqlerrml));
}


}

void ProcConnectionImpl::close() {
    
}

void ProcConnectionImpl::setAutoCommit(boolean autoCommit) {
    
}

boolean ProcConnectionImpl::getAutoCommit() {
    return true;
}

Statement ProcConnectionImpl::createStatement(String sql) {
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        const char* proc_sql;
    /* EXEC SQL END DECLARE SECTION; */ 

    
    proc_sql = sql->toChar();
    
    /* EXEC SQL WHENEVER SQLERROR DO throwException(sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc, sqlca.sqlerrm.sqlerrml); */ 

    /* EXEC SQL FOR 100 ALLOCATE DESCRIPTOR GLOBAL 'in'; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )100;
    sqlstm.offset = (unsigned int  )66;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )100;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) throwException((sqlca.sqlcode),((sqlca.sqlerrm).sqlerrmc),((sqlca.sqlerrm).sqlerrml));
}


    /* EXEC SQL FOR 100 ALLOCATE DESCRIPTOR GLOBAL 'out'; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )100;
    sqlstm.offset = (unsigned int  )83;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )100;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) throwException((sqlca.sqlcode),((sqlca.sqlerrm).sqlerrmc),((sqlca.sqlerrm).sqlerrml));
}


    /* EXEC SQL PREPARE STMT FROM :proc_sql; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )101;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)proc_sql;
    sqlstm.sqhstl[0] = (unsigned long )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) throwException((sqlca.sqlcode),((sqlca.sqlerrm).sqlerrmc),((sqlca.sqlerrm).sqlerrml));
}


    /* EXEC SQL DECLARE C CURSOR FOR STMT; */ 

    
    return ProcStatement::newInstance();
}
