
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
           char  filnam[44];
};
static const struct sqlcxp sqlfpn =
{
    43,
    "../../../../src/sql/proc/ProcResultSet.pcxx"
};


static unsigned int sqlctx = 1597901644;


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


#include "jam/sql/proc/ProcResultSet.hxx"
#include "jam/sql/proc/ProcResultSetMetaData.hxx"
#include "jam/lang/Object.hxx"
#include "jam/lang/Class.hxx"
#include "jam/lang/String.hxx"
#include "jam/util/time/Calendar.hxx"

using namespace jam::sql;
using namespace jam::sql::proc;
using namespace jam::lang;
using namespace jam::util::time;

const Class ProcResultSet::klass = Class::newInstance("jam::sql::proc::ProcResultSet");

ProcResultSet::ProcResultSet() : ResultSet() {
    //
}

ProcResultSet::ProcResultSet(const Reference& ref) : ResultSet(ref) {
    //
}

ProcResultSet::ProcResultSet(Implementation* impl) : ResultSet(impl) {
    //
}

ProcResultSet::~ProcResultSet() {
    //
}

ProcResultSetImpl& ProcResultSet::operator*() {
    return (ProcResultSetImpl&) ResultSet::operator*();
}

ProcResultSetImpl* ProcResultSet::operator->() {
    return (ProcResultSetImpl*) ResultSet::operator->();
}

const ProcResultSet& ProcResultSet::operator=(const Reference& ref) {
    return (ProcResultSet&) ResultSet::operator=(ref);
}

const ProcResultSet& ProcResultSet::operator=(Implementation* impl) {
    return (ProcResultSet&) ResultSet::operator=(impl);
}

ProcResultSet ProcResultSet::newInstance() {
    return ProcResultSet(new ProcResultSetImpl());
}

/*** Implementation ***/

ProcResultSetImpl::ProcResultSetImpl() {
    //
}

ProcResultSetImpl::~ProcResultSetImpl() {
    //
}

ProcResultSetImpl::ProcResultSetImpl(const ProcResultSetImpl& copy) {
    //
}

#ifdef __DEBUG__
const char* ProcResultSetImpl::debugClassName() {
    return "jam::sql::proc::ProcResultSet";
}
#endif

boolean ProcResultSetImpl::next() {
    return true;
}

boolean ProcResultSetImpl::previous() {
    return true;
}

void ProcResultSetImpl::close() {
    
}

ResultSetMetaData ProcResultSetImpl::getMetaData() {
    return null;
}

int ProcResultSetImpl::getInteger(int index) {
    return 0;
}

int ProcResultSetImpl::getInteger(String column) {
    return 0;
}

long ProcResultSetImpl::getLong(int index) {
    return 0;
}

long ProcResultSetImpl::getLong(String column) {
    return 0;
}

double ProcResultSetImpl::getDouble(int index) {
    return 0.0;
}

double ProcResultSetImpl::getDouble(String column) {
    return 0.0;
}

String ProcResultSetImpl::getString(int index) {
    return null;
}

String ProcResultSetImpl::getString(String column) {
    return null;
}

Calendar ProcResultSetImpl::getCalendar(int index) {
    return null;
}

Calendar ProcResultSetImpl::getCalendar(String column) {
    return null;
}
