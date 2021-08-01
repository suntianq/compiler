
main.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 20          	sub    $0x20,%rsp
   8:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
   f:	00 00 
  11:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  15:	31 c0                	xor    %eax,%eax
  17:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
  1e:	c7 45 e8 01 00 00 00 	movl   $0x1,-0x18(%rbp)
  25:	c7 45 ec 01 00 00 00 	movl   $0x1,-0x14(%rbp)
  2c:	c7 45 f0 64 00 00 00 	movl   $0x64,-0x10(%rbp)
  33:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  37:	48 89 c6             	mov    %rax,%rsi
  3a:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # 41 <main+0x41>
  41:	b8 00 00 00 00       	mov    $0x0,%eax
  46:	e8 00 00 00 00       	callq  4b <main+0x4b>
  4b:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  4e:	89 c6                	mov    %eax,%esi
  50:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # 57 <main+0x57>
  57:	b8 00 00 00 00       	mov    $0x0,%eax
  5c:	e8 00 00 00 00       	callq  61 <main+0x61>
  61:	8b 45 e8             	mov    -0x18(%rbp),%eax
  64:	89 c6                	mov    %eax,%esi
  66:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # 6d <main+0x6d>
  6d:	b8 00 00 00 00       	mov    $0x0,%eax
  72:	e8 00 00 00 00       	callq  77 <main+0x77>
  77:	eb 2c                	jmp    a5 <main+0xa5>
  79:	8b 45 e8             	mov    -0x18(%rbp),%eax
  7c:	89 45 f4             	mov    %eax,-0xc(%rbp)
  7f:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  82:	01 45 e8             	add    %eax,-0x18(%rbp)
  85:	8b 45 e8             	mov    -0x18(%rbp),%eax
  88:	89 c6                	mov    %eax,%esi
  8a:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # 91 <main+0x91>
  91:	b8 00 00 00 00       	mov    $0x0,%eax
  96:	e8 00 00 00 00       	callq  9b <main+0x9b>
  9b:	8b 45 f4             	mov    -0xc(%rbp),%eax
  9e:	89 45 e4             	mov    %eax,-0x1c(%rbp)
  a1:	83 45 ec 01          	addl   $0x1,-0x14(%rbp)
  a5:	8b 45 e0             	mov    -0x20(%rbp),%eax
  a8:	39 45 ec             	cmp    %eax,-0x14(%rbp)
  ab:	7c cc                	jl     79 <main+0x79>
  ad:	b8 00 00 00 00       	mov    $0x0,%eax
  b2:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  b6:	64 48 33 14 25 28 00 	xor    %fs:0x28,%rdx
  bd:	00 00 
  bf:	74 05                	je     c6 <main+0xc6>
  c1:	e8 00 00 00 00       	callq  c6 <main+0xc6>
  c6:	c9                   	leaveq 
  c7:	c3                   	retq   
