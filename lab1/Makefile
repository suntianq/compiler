.PHONY: pre, ast, ir, asm, obj, exe, antiobj, antiexe

pre:
	gcc main.c -E -o main.i

 # 生成`main.c.003t.original`
ast:
	gcc -fdump-tree-original-raw main.c

 # 会生成多个阶段的文件(.dot)，可以被graphviz 可视化，可以直接使用vscode 插件
 # (Graphviz (dot) language support for Visual Studio Code)。
 # 此时的可读性还很强。`main.c.011t.cfg.dot`
cfg:
	gcc -O0 -fdump-tree-all-graph main.c

 # 此时可读性不好，简要了解各阶段更迭过程即可。
ir:
	gcc -O0 -fdump-rtl-all-graph main.c

asm:
	gcc -O0 -o main.S -S -masm=att main.i

obj:
	gcc -O0 -c -o main.o main.S

antiobj:
	objdump -d main.o > main-anti-obj.S
	nm main.o > main-nm-obj.txt

exe:
	gcc -O0 -o main main.o

antiexe:
	objdump -d main > main-anti-exe.S
	nm main > main-nm-exe.txt

clean:
	rm *.c.*

clean-all:
	rm *.c.* *.o *.S *.dot *.out *.txt main
