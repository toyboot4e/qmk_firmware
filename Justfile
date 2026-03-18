# Just a task runner
# <https://github.com/casey/just>

# shows this help message
help:
    @just -l

c:
    qmk compile -kb toyboot4e/mejiro31 -km default

db:
    qmk compile --compiledb -kb toyboot4e/mejiro31 -km default

f:
    qmk flash -kb toyboot4e/mejiro31 -km default
