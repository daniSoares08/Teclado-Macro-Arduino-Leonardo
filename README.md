# 🎛️ Arduino Macro Pad com Controle de Volume

Este projeto transforma um **Arduino Leonardo** (ou qualquer placa compatível com HID, como Pro Micro) em um **teclado de macros programável** com:
- **Botões** físicos para atalhos de teclado
- **Potenciômetro** analógico para controlar o volume do sistema
- Envio de **códigos de acesso ou strings** ao pressionar botões
- Compatível com Windows, Linux e macOS

## 🔧 Funcionalidades

| Pino | Função                                         |
|------|------------------------------------------------|
| 7    | Envia `Alt + P`                                |
| 8    | Atalho `Ctrl + X` (Cortar)                     |
| 9    | Digita o número `6`                            |
| 10   | Atalho `Ctrl + Z` (Desfazer)                   |
| 11   | Digita o código `"email 1"`            |
| 12   | Digita o código `"email 2"`           |
| 13   | Digita o código `"email 3"`           |
| 16   | Atalho `Ctrl + Y` (Refazer)                    |
| A0   | Potenciômetro para controle de volume do sistema |

> As teclas funcionam quando os pinos são aterrados (ligados ao GND), usando botões de pulldown.

---

## 🧰 Requisitos

- Placa Arduino Leonardo, Pro Micro, ou similar com suporte HID
- Biblioteca [HID-Project](https://github.com/NicoHood/HID)
- Potenciômetro de 10k ohms
- Botões momentâneos (push button)
- IDE Arduino

---

## 📦 Instalação

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/nome-do-repositorio.git
   ```

2. Abra o código na IDE Arduino

3. Instale a biblioteca `HID-Project`:

   * Vá em **Sketch > Incluir Biblioteca > Gerenciar Bibliotecas**
   * Pesquise por **HID-Project** e instale

4. Compile e envie o código para sua placa

---

## 🎯 Exemplo de uso

* Gire o potenciômetro: controla o volume do sistema
* Pressione o botão do pino 8: corta texto (Ctrl + X)
* Pressione o botão do pino 7: executa Alt + P

---

## 🛠️ Customização

Você pode editar facilmente o código para adicionar:

* Novos atalhos
* Strings personalizadas
* Combinações de teclas
* Mudança do comportamento do potenciômetro (ex: brilho de tela)

---

## ✍️ Autor

**Daniel Soares**
Estudante de Engenharia da Computação, apaixonado por automações, redes e desenvolvimento full stack.

🔗 [LinkedIn](https://www.linkedin.com/in/daniel-campos-soares-b47426238/)
