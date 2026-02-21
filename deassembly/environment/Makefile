# (C) Antonio Maulucci 2026

# Compilatore da usare per sistemi Linux/macOS/POSIX
CC      = gcc

# Compilatore da usare per sistemi Windows (path completo a MinGW)
CC_WINDOWS = C:/MinGW/bin/gcc.exe

# Path completo al debugger GDB fornito da MinGW su Windows
GDB_WINDOWS = C:/MinGW/bin/gdb.exe

# Flag di compilazione di default: vuoti, nessuna opzione aggiuntiva
CFLAGS =

# Opzioni di compilazione per la modalità debug:
#   -Wall    abilita i warning più comuni (possibili errori nel codice)
#   -Wextra  abilita warning aggiuntivi rispetto a -Wall
#   -g3      include informazioni di debug al massimo livello (incluse le macro)
#             queste informazioni permettono a GDB di mostrare il codice sorgente
#             durante il debug, altrimenti vedrebbe solo istruzioni assembler
#   -O0      disabilita le ottimizzazioni del compilatore: senza questa opzione
#             il compilatore potrebbe riorganizzare o eliminare istruzioni,
#             rendendo il debug confuso e impreciso
DEBUG_CFLAGS  = -Wall -Wextra -g3 -O0

# Flag per la compilazione su Windows:
# equivale a scrivere #define IS_WINZOZZ 1 nel codice sorgente,
# permettendo di attivare porzioni di codice specifiche per Windows
# tramite direttive #ifdef IS_WINZOZZ ... #endif
WINZOZZ_CFLAGS = -DIS_WINZOZZ=1

# Flag per compilazione Windows in modalità debug:
# combina i flag di debug con la define IS_WINZOZZ
WINZOZZ_DEBUG_CFLAGS = $(DEBUG_CFLAGS) $(WINZOZZ_CFLAGS)

# Nome del file eseguibile prodotto dalla compilazione su Linux/macOS
TARGET  = main

# Nome del file eseguibile prodotto dalla compilazione su Windows
# su Windows gli eseguibili hanno estensione .exe
WINDOWS_TARGET = main.exe

# File sorgente C da compilare
SRC     = main.c

# Nome del file assembly generato dalla compilazione su Linux/macOS.
# Il file .s contiene le istruzioni assembly corrispondenti al codice C,
# cioè il linguaggio a basso livello che il processore esegue direttamente.
ASM_TARGET = main.s

# Nome del file assembly generato dalla compilazione su Windows.
# Viene tenuto separato da quello Linux perché le due piattaforme
# usano convenzioni di chiamata diverse e producono assembly diverso.
WINDOWS_ASM_TARGET = main_windows.s

# .PHONY dice a make che questi sono nomi di regole e non file reali su disco.
# Senza .PHONY, se esistesse un file chiamato "clean" nella directory,
# make penserebbe che sia già aggiornato e non eseguirebbe la regola.
.PHONY: all clean debug run winzozz winzozz_debug asm asm_debug asm_winzozz asm_winzozz_debug

# Regola per compilare il sorgente e produrre l'eseguibile per Linux/macOS.
# $(TARGET) è un FILE REALE su disco: make confronta la data di modifica
# di "main" con quella di "main.c". Se il sorgente è più recente,
# ricompila. Se l'eseguibile è già aggiornato, make non fa nulla.
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Regola per compilare il sorgente e produrre l'eseguibile per Windows.
# Usa $(CC_WINDOWS) al posto di $(CC) per invocare il compilatore MinGW
# che genera un .exe compatibile con Windows.
# Anche $(WINDOWS_TARGET) è un file reale: vale lo stesso meccanismo
# di controllo data descritto sopra.
$(WINDOWS_TARGET): $(SRC)
	$(CC_WINDOWS) $(CFLAGS) -o $(WINDOWS_TARGET) $(SRC)

# Regola di default: viene eseguita quando si lancia "make" senza argomenti.
# Dipende da $(TARGET), quindi compila l'eseguibile per Linux/macOS.
all: $(TARGET)

# Regola per generare il codice assembly su Linux/macOS.
# "asm" è in .PHONY quindi make esegue sempre questo comando,
# senza controllare se il file .s esiste già o è aggiornato.
# -S dice a gcc di fermarsi prima della fase di assemblaggio e produrre
# un file .s con le istruzioni assembly invece dell'eseguibile.
# -masm=intel usa la sintassi Intel (più leggibile rispetto alla
# sintassi AT&T che è quella di default su Linux).
asm: $(SRC)
	$(CC) $(CFLAGS) -S -masm=intel -o $(ASM_TARGET) $(SRC)

# Regola per generare il codice assembly su Linux/macOS in modalità debug.
# Usando $(DEBUG_CFLAGS) con -O0 l'assembly prodotto è più fedele
# al codice C originale: senza ottimizzazioni ogni riga C corrisponde
# a istruzioni assembly ben identificabili, rendendo più facile
# capire cosa sta facendo il processore.
asm_debug: CFLAGS = $(DEBUG_CFLAGS)
asm_debug: $(SRC)
	$(CC) $(CFLAGS) -S -masm=intel -o $(ASM_TARGET) $(SRC)

# Regola per generare il codice assembly su Windows.
# Usa $(CC_WINDOWS) per produrre assembly compatibile con le convenzioni
# di chiamata Windows (Microsoft x64 ABI), che sono diverse da quelle
# Linux (System V AMD64 ABI). Questo significa che i registri usati
# per passare parametri alle funzioni sono diversi tra i due sistemi.
asm_winzozz: $(SRC)
	$(CC_WINDOWS) $(WINZOZZ_CFLAGS) -S -masm=intel -o $(WINDOWS_ASM_TARGET) $(SRC)

# Regola per generare il codice assembly su Windows in modalità debug.
# Combina i flag di debug con la define IS_WINZOZZ=1, producendo
# assembly non ottimizzato e con informazioni di debug incluse.
asm_winzozz_debug: $(SRC)
	$(CC_WINDOWS) $(WINZOZZ_DEBUG_CFLAGS) -S -masm=intel -o $(WINDOWS_ASM_TARGET) $(SRC)

# Regola per compilare e avviare il debugger GDB su Linux/macOS.
# "debug: CFLAGS = $(DEBUG_CFLAGS)" è una variabile target-specific:
# sovrascrive CFLAGS solo per questa regola, aggiungendo i flag di debug.
# GDB permette di eseguire il programma passo passo, ispezionare variabili,
# impostare breakpoint e capire cosa succede durante l'esecuzione.
debug: CFLAGS = $(DEBUG_CFLAGS)
debug: $(TARGET)
	gdb ./$(TARGET)

# Regola per compilare ed avviare GDB su Windows in modalità debug.
# Usa $(GDB_WINDOWS) con il path completo per assicurarsi di usare
# il GDB di MinGW, compatibile con i binari prodotti da $(CC_WINDOWS).
# Combina i flag di debug con la define IS_WINZOZZ=1.
winzozz_debug: CFLAGS = $(WINZOZZ_DEBUG_CFLAGS)
winzozz_debug: $(WINDOWS_TARGET)
	$(GDB_WINDOWS) ./$(WINDOWS_TARGET)

# Regola per compilare ed eseguire direttamente il programma su Linux/macOS,
# senza avviare il debugger.
run: $(TARGET)
	./$(TARGET)

# Regola per compilare ed eseguire il programma su Windows.
# "winzozz: CFLAGS = $(WINZOZZ_CFLAGS)" è una variabile target-specific:
# aggiunge il flag -DIS_WINZOZZ=1 solo per questa compilazione,
# attivando nel codice sorgente le sezioni specifiche per Windows.
winzozz: CFLAGS = $(WINZOZZ_CFLAGS)
winzozz: $(WINDOWS_TARGET)
	./$(WINDOWS_TARGET)

# Regola per pulire la directory di lavoro.
# Rimuove tutti i file prodotti dalla compilazione: eseguibili e file assembly.
# "rm -f" non dà errore se i file non esistono (-f = force).
# Utile per forzare una ricompilazione completa da zero.
clean:
	rm -f $(TARGET) $(WINDOWS_TARGET) $(ASM_TARGET) $(WINDOWS_ASM_TARGET)

# ---------------------------------------------------------------------------
# NOTA: DIFFERENZA TRA COMANDI DIRETTI E TARGET CON DIPENDENZE DA FILE REALI
# ---------------------------------------------------------------------------
#
# In questo Makefile esistono due modi diversi di definire una regola:
#
# --- MODO 1: target che produce un FILE REALE su disco ---
#
#   $(TARGET): $(SRC)
#       $(CC) $(CFLAGS) -o $(TARGET) $(SRC)
#
#   In questo caso "main" è un file che viene effettivamente creato su disco.
#   Make controlla le date di modifica: se "main.c" è stato modificato dopo
#   l'ultima compilazione di "main", allora ricompila. Altrimenti non fa nulla
#   e stampa: make: 'main' is up to date
#   Questo meccanismo evita ricompilazioni inutili e risparmia tempo.
#
# --- MODO 2: target dichiarato in .PHONY (comando diretto) ---
#
#   asm: $(SRC)
#       $(CC) $(CFLAGS) -S -masm=intel -o $(ASM_TARGET) $(SRC)
#
#   In questo caso "asm" NON è un file su disco ma un semplice nome di regola.
#   Essendo dichiarato in .PHONY, make ignora completamente il controllo
#   delle date e riesegue sempre il comando, ogni volta che si lancia "make asm".
#   Senza .PHONY, se per caso esistesse un file chiamato "asm" nella directory,
#   make penserebbe che sia già aggiornato e non eseguirebbe nulla.
#
# --- QUANDO USARE L'UNO O L'ALTRO ---
#
#   Si usa un target con file reale quando il risultato della regola è
#   un file su disco (un eseguibile, un file oggetto .o, un file assembly .s)
#   e si vuole che make eviti di ricompilare se non è necessario.
#
#   Si usa .PHONY quando la regola rappresenta un'azione (pulire, eseguire,
#   avviare il debugger) che non produce un file con lo stesso nome del target,
#   oppure quando si vuole che il comando venga eseguito sempre
#   indipendentemente da cosa c'è su disco.
#
# ---------------------------------------------------------------------------

