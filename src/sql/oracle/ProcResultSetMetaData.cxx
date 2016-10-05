
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
           char  filnam[52];
};
static const struct sqlcxp sqlfpn =
{
    51,
    "../../../../src/sql/proc/ProcResultSetMetaData.pcxx"
};


static unsigned int sqlctx = 1040805100;


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
   unsigned char  *sqhstv[1];
   unsigned long  sqhstl[1];
            int   sqhsts[1];
            short *sqindv[1];
            int   sqinds[1];
   unsigned long  sqharm[1];
   unsigned long  *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

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
};


#include "jam/sql/proc/ProcResultSetMetaData.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"

using namespace jam::sql;
using namespace jam::sql::proc;
using namespace jam::lang;

const Class ProcResultSetMetaData::klass = Class::newInstance("jam::sql::proc::ProcResultSetMetaData");

ProcResultSetMetaData::ProcResultSetMetaData() : ResultSetMetaData() {
    //
}

ProcResultSetMetaData::ProcResultSetMetaData(const Reference& ref) : ResultSetMetaData(ref) {
    //
}

ProcResultSetMetaData::ProcResultSetMetaData(Implementation* impl) : ResultSetMetaData(impl) {
    //
}

ProcResultSetMetaData::~ProcResultSetMetaData() {
    //
}

ProcResultSetMetaDataImpl& ProcResultSetMetaData::operator*() {
    return (ProcResultSetMetaDataImpl&) ResultSetMetaData::operator*();
}

ProcResultSetMetaDataImpl* ProcResultSetMetaData::operator->() {
    return (ProcResultSetMetaDataImpl*) ResultSetMetaData::operator->();
}

const ProcResultSetMetaData& ProcResultSetMetaData::operator=(const Reference& ref) {
    return (ProcResultSetMetaData&) ResultSetMetaData::operator=(ref);
}

const ProcResultSetMetaData& ProcResultSetMetaData::operator=(Implementation* impl) {
    return (ProcResultSetMetaData&) ResultSetMetaData::operator=(impl);
}

/*** Implementation ***/

ProcResultSetMetaDataImpl::ProcResultSetMetaDataImpl() {
    //
}

ProcResultSetMetaDataImpl::~ProcResultSetMetaDataImpl() {
    //
}

ProcResultSetMetaDataImpl::ProcResultSetMetaDataImpl(const ProcResultSetMetaDataImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ProcResultSetMetaDataImpl::debugClassName() {
    return "jam::sql::proc::ProcResultSetMetaData";
}
#endif

int ProcResultSetMetaDataImpl::getColumnCount() {
    return 0;
}

String ProcResultSetMetaDataImpl::getColumnName(int index) {
    return null;
}

int ProcResultSetMetaDataImpl::getColumnType(int index) {
    return 0;
}

String ProcResultSetMetaDataImpl::getColumnTypeName(int index) {
    return null;
}
