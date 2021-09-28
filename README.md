# overview

using [platformio](https://docs.platformio.org/en/latest/platforms/ststm32.html) for building and deploying stm32 firmware.

Using [arduino](platformio.ini) framework.


## lsp in emacs

Create a compile\_commands.json inside .pio and symlink it into the root directory.

```bash
pio run -t compiledb
```