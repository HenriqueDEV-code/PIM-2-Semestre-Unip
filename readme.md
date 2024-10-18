# Gestão Hortifruti PIM

Gestão de Hortifruti PIM (Breve Descrição do Projeto)

## Instalação

Primeiro será necessário o uso de um compilador [GCC](https://sourceforge.net/projects/gcc-win64/) ou o uso do Visual Studio.

### Estrutura de Pastas:

``` bash
│   Gestão Hortifruti PIM.sln
│
├───Gestão Hortifruti PIM
│   │   Gestão Hortifruti PIM.vcxproj
│   │   Gestão Hortifruti PIM.vcxproj.filters
│   │   Gestão Hortifruti PIM.vcxproj.user
│   │
│   ├───dist
│   │       app.exe
│   │
│   ├───include
│   │       Estruturas.h
│   │       Titulos.h
│   │
│   ├───src
│   │       main.c
│   │
│   └───x64
│       └───Debug
│           │   Gestão Hortifruti PIM.exe.recipe
│           │   Gestão Hortifruti PIM.ilk
│           │   Gestão Hortifruti PIM.log
│           │   main.obj
│           │   vc143.idb
│           │   vc143.pdb
│           │
│           └───Gestão H.5b6e3f1f.tlog
│                   CL.command.1.tlog
│                   Cl.items.tlog
│                   CL.read.1.tlog
│                   CL.write.1.tlog
│                   Gestão Hortifruti PIM.lastbuildstate
│                   link.command.1.tlog
│                   link.read.1.tlog
│                   link.secondary.1.tlog
│                   link.write.1.tlog
│
└───x64
    └───Debug
            Gestão Hortifruti PIM.exe
            Gestão Hortifruti PIM.pdb
```

## Uso

Os principais arquivos de código estão na pasta `src`, incluindo o `main.c.` Para compilar e usar a aplicação, utilize o seguinte comando no `CLI`:


``` bash

gcc main.c -o ../dist/app.exe

```

Após compilar, a aplicação está localizada em um arquivo `.exe` no caso como você nomeou no comando. Usa-se:

``` powershell

..\PIM-2-Semestre-Unip\Gestão Hortifruti PIM\Gestão Hortifruti PIM\dist> .\app.exe

```

https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

## Contribuindo

(Normas de Commit)