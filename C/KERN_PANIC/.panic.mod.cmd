savedcmd_panic.mod := printf '%s\n'   panic.o | awk '!x[$$0]++ { print("./"$$0) }' > panic.mod
