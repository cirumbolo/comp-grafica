# Project Instructions: Computer Graphics (INF01047)

This file contains foundational mandates for Gemini CLI while working on this project. These instructions take absolute precedence over general defaults.

## Project Overview
This is a Computer Graphics project for the INF01047 course at UFRGS. It uses OpenGL, GLFW, GLAD, and GLM.

## Conventions
- **Language:** C++
- **Graphics API:** OpenGL 3.3+ Core Profile
- **Math Library:** GLM
- **Naming:** Follow existing patterns in the codebase (e.g., camelCase for variables, Snake_Case or similar for shaders if applicable).
- **Comments:** Prefer clear, descriptive code. Use comments for complex logic.

## Workflows

### Building and Running
The preferred method is using CMake.

#### Linux
```bash
cmake --workflow --preset configure-build-run
```
Or manually:
```bash
cmake -B build -S .
cmake --build build
cmake --build build -- run
```

#### Windows (MinGW/GCC)
Ensure GCC and CMake are in your PATH. Use the VSCode CMake Tools extension or run:
```bash
cmake -B build -S . -G "MinGW Makefiles"
cmake --build build
./build/main.exe
```

### Cleaning
```bash
cmake --build build -- clean
```

## Instruction Updates
If you want to change how I interact with you or this project, you can:
1.  **Ask me to update this file:** "Update GEMINI.md to always use X convention."
2.  **Edit it yourself:** I will pick up the changes in the next turn.
3.  **Add subdirectory instructions:** Create a `GEMINI.md` in a specific folder for local rules.

## Core Mandates
- **Validation:** Always verify changes by building the project.
- **Surgical Edits:** Use `replace` for precise modifications.
- **Documentation:** Keep `GEMINI.md` updated with new architectural decisions.

## Git Conventions
- **Idioma:** As mensagens de commit devem ser sempre em **Português**.
- **Formato:** Use mensagens simples e diretas, sem corpo ou descrição longa.
- **Sistema de Tags:** Todo commit deve iniciar com uma tag indicando a autoria:
  - `[AI]` para commits gerados ou sugeridos pelo assistente.
  - `[HUMANO]` para commits solicitados ou revisados integralmente por você.
  - **Ação:** Sempre pergunte qual tag utilizar antes de realizar o commit.
- **Co-autores:** Todos os commits devem incluir os seguintes co-autores no final da mensagem (pule uma linha antes):
  ```text
  Co-authored-by: Guilherme Cirumbolo <gcirumbolo@gmail.com>
  Co-authored-by: Alles725 <pedroma2001@gmail.com>
  ```
