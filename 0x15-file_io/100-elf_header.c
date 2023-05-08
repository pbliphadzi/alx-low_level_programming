#include "main.h"

void check_elf(unsigned char *e_ident)
{
    const unsigned char elf_magic[] = { 0x7f, 'E', 'L', 'F' };
    if (memcmp(e_ident, elf_magic, sizeof(elf_magic)) != 0) {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        exit(98);
    }
}

void print_magic(unsigned char *e_ident)
{
    printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x "
           "%02x %02x %02x %02x %02x %02x %02x %02x\n",
           e_ident[0], e_ident[1], e_ident[2], e_ident[3],
           e_ident[4], e_ident[5], e_ident[6], e_ident[7],
           e_ident[8], e_ident[9], e_ident[10], e_ident[11],
           e_ident[12], e_ident[13], e_ident[14], e_ident[15]);
}

void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");

    if (e_ident[EI_CLASS] == ELFCLASSNONE) {
        printf("none\n");
    } else if (e_ident[EI_CLASS] == ELFCLASS32) {
        printf("ELF32\n");
    } else if (e_ident[EI_CLASS] == ELFCLASS64) {
        printf("ELF64\n");
    } else {
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");

    if (e_ident[EI_DATA] == ELFDATANONE) {
        printf("none\n");
    } else if (e_ident[EI_DATA] == ELFDATA2LSB) {
        printf("2's complement, little endian\n");
    } else if (e_ident[EI_DATA] == ELFDATA2MSB) {
        printf("2's complement, big endian\n");
    } else {
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

void print_version(unsigned char *e_ident)
{
    printf("  Version:                           %d", e_ident[EI_VERSION]);

    if (e_ident[EI_VERSION] == EV_CURRENT) {
        printf(" (current)\n");
    } else {
        printf("\n");
    }
}

void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");

    if (e_ident[EI_OSABI] == ELFOSABI_NONE) {
        printf("UNIX - System V\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_HPUX) {
        printf("UNIX - HP-UX\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD) {
        printf("UNIX - NetBSD\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_LINUX) {
        printf("UNIX - Linux\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS) {
        printf("UNIX - Solaris\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_IRIX) {
        printf("UNIX - IRIX\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD) {
        printf("UNIX - FreeBSD\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_TRU64) {
        printf("UNIX - TRU64\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_ARM) {
        printf("ARM\n");
    } else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE) {
        printf("Standalone App\n");
    } else {
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

void print_type(unsigned int e_type, unsigned char *e_ident)
{
    printf("  Type:                              ");

    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_type >>= 8;
    }

    if (e_type == ET_NONE)
    {
        printf("NONE (None)\n");
    }
    else if (e_type == ET_REL)
    {
        printf("REL (Relocatable file)\n");
    }
    else if (e_type == ET_EXEC)
    {
        printf("EXEC (Executable file)\n");
    }
    else if (e_type == ET_DYN)
    {
        printf("DYN (Shared object file)\n");
    }
    else if (e_type == ET_CORE)
    {
        printf("CORE (Core file)\n");
    }
    else
    {
        printf("<unknown: %x>\n", e_type);
    }
}

