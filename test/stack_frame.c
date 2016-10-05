
/*
 * User-space might still rely on the old definition:
 */
 
 // 32-bit
 struct sigcontext {
	unsigned short gs, __gsh;
	unsigned short fs, __fsh;
	unsigned short es, __esh;
	unsigned short ds, __dsh;
	unsigned long edi;
	unsigned long esi;
	unsigned long ebp;
	unsigned long esp;
	unsigned long ebx;
	unsigned long edx;
	unsigned long ecx;
	unsigned long eax;
	unsigned long trapno;
	unsigned long err;
	unsigned long eip;
	unsigned short cs, __csh;
	unsigned long eflags;
	unsigned long esp_at_signal;
	unsigned short ss, __ssh;
	struct _fpstate *fpstate;
	unsigned long oldmask;
	unsigned long cr2;
};

// 64-bit
struct sigcontext {
	__u64 r8;
	__u64 r9;
	__u64 r10;
	__u64 r11;
	__u64 r12;
	__u64 r13;
	__u64 r14;
	__u64 r15;
	__u64 rdi;
	__u64 rsi;
	__u64 rbp;
	__u64 rbx;
	__u64 rdx;
	__u64 rax;
	__u64 rcx;
	__u64 rsp;
	__u64 rip;
	__u64 eflags;		/* RFLAGS */
	__u16 cs;
	__u16 gs;
	__u16 fs;
	__u16 __pad0;
	__u64 err;
	__u64 trapno;
	__u64 oldmask;
	__u64 cr2;
	struct _fpstate *fpstate;	/* zero when no FPU context */
#ifdef __ILP32__
	__u32 __fpstate_pad;
#endif
	__u64 reserved1[8];
};
