
# istruzioni valide per x86-64 su arm

## Installazione delle dipendenze etc

```bash
sudo apt update
sudo apt install -y gcc-x86-64-linux-gnu gdb-multiarch qemu-user
```

### check delle dipendenze 

```bash
ls /usr/x86_64-linux-gnu/lib64/ld-linux-x86-64.so.2
```

## compila

```bash
make onarm
```

## esegui shell 1

```bash
qemu-x86_64 -L /usr/x86_64-linux-gnu -g 1234 ./main_x86_64
```

## esegui shell 2

```bash
gdb-multiarch ./main_x86_64
```

e poi, nella shell di gdb

```bash
set architecture i386:x86-64
target remote :1234
b main.c:6
c
```

## stampa valore dei registri

```bash
print/d $eax
print/d $edx
```
