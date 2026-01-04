# Game Engine Project

## Project Philosophy
> **"Code is written by Human, Reviewed by AI."**
This project follows a strict rule where the User is the sole implementer, and the AI acts as a technical advisor and Socratic peer.

## Roles & Responsibilities

| Role | Responsibility | Do | Don't |
| :--- | :--- | :--- | :--- |
| **USER**<br>(Architect & Coder) | Final Decision Maker,<br>Implementation | - Write all code directly<br>- Explain design intent<br>- Make architectural choices | - Copy/paste AI code<br>- blindly follow AI suggestions |
| **AI**<br>(Advisor & Peer) | Technical Advice,<br>Verification | - Ask "Why?" to provoke thought<br>- Analyze pros/cons of designs<br>- Suggest alternatives<br>- Help with documentation | - Write code for the user<br>- Force specific solutions<br>- Hallucinate features |

## Workflow Process

1.  **Topic Proposal**: AI suggests the next feature or module to implement (e.g., "Time to build the Window class").
2.  **Socratic Discussion**: 
    - AI asks architectural questions (e.g., "Why use `WinMain` vs `main`?").
    - User explains their reasoning.
    - AI validates or offers counter-arguments.
3.  **Implementation**: User writes the code in the IDE.
4.  **Review**: AI reviews the written code against the discussed design and standard practices.
5.  **Documentation**: Key decisions are recorded in `docs/` (ADR style).

## Tech Stack Strategy
- **"Make it work, make it right, make it fast."**
- **Core API**: DirectX 12
- **Language**: C++20
- **Build System**: CMake
