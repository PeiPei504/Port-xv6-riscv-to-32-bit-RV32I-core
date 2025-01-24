void
trapinithart(void)
{
 w_stvec((uintptr_t)kernelvec);
}




 // tell trampoline.S the user page table to switch to.
  uint32 satp = MAKE_SATP(p->pagetable);

  // jump to userret in trampoline.S at the top of memory, which
  // switches to the user page table, restores user registers,
  // and switches to user mode with sret.
  uintptr_t trampoline_userret = TRAMPOLINE + (userret - trampoline);
  (void)trampoline_userret;
  ((void (*)(uintptr_t))trampoline_userret)((uintptr_t)satp);
}




p->trapframe->kernel_satp = r_satp();         // kernel page table
  p->trapframe->kernel_sp = p->kstack + PGSIZE; // process's kernel stack
  p->trapframe->kernel_trap = (uintptr_t)usertrap;
  p->trapframe->kernel_hartid = r_tp();         // hartid for cpuid()
