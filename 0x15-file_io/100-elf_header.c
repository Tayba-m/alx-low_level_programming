#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ch_elf(unsigned char *e_id);
void p_magic(unsigned char *e_id);
void p_class(unsigned char *e_id);
void p_data(unsigned char *e_id);
void p_version(unsigned char *e_id);
void p_abi(unsigned char *e_id);
void p_osabi(unsigned char *e_id);
void p_type(unsigned int e_ty, unsigned char *e_id);
void p_entry(unsigned long int e_en, unsigned char *e_id);
void cl_elf(int elf);

/**
 * ch_elf - Checks file
 * @e_id: pointer
 *
 */
void ch_elf(unsigned char *e_id)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_id[i] != 127 && e_id[i] != 'E'
			&& e_id[i] != 'L' && e_id[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * p_magic - Prints magic numbers
 * @e_id: pointer
 */
void p_magic(unsigned char *e_id)
{
	int i;

	printf(" Magic: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_id[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * p_class - Prints the class of an ELF header.
 * @e_id: pointer
 */
void p_class(unsigned char *e_id)
{
	printf(" Class: ");

	switch (e_id[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 * p_data - Prints data header.
 * @e_id: pointer
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_id[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ide[EI_CLASS]);
	}
}

/**
 *  * p_version - Prints header.
 *   * @e_id: A pointer to an array containing the ELF version.
 */
void p_version(unsigned char *e_id)
{
	 printf(" Version: %d",
			  e_id[EI_VERSION]);

	switch (e_id[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * p_osabi - Prints eader.
 * @e_id: pointer
 */
void p_osabi(unsigned char *e_id)
{
	printf(" OS/ABI: ");

	switch (e_id[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_OSABI]);
	}
}

/**
 * p_abi - Prints  header.
 * @e_id: pointer
 *
 */
void p_abi(unsigned char *e_id)
{
	printf(" ABI Version: %d\n",
		e_id[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_ty: ELF type.
 * @e_id: pointer
 */
void p_type(unsigned int e_ty, unsigned char *e_id)
{
	if (e_id[EI_DATA] == ELFDATA2MSB)
		e_ty >>= 8;

	printf(" Type: ");

	switch (e_ty)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ty);
	}
}

/**
 * p_entry - Prints hadrr
 * @e_en: address
 * @e_id: pointer
 */
void p_entry(unsigned long int e_en, unsigned char *e_id)
{
	printf(" Entry point address: ");

	if (e_id[EI_DATA] == ELFDATA2MSB)
	{
		e_en = ((e_en << 8) & 0xFF00FF00) |
			  ((e_en >> 8) & 0xFF00FF);
		e_en = (e_en << 16) | (e_en >> 16);
	}

	if (e_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_en);

	else
		printf("%#lx\n", e_en);
}

/**
 * cl_elf - Closes an ELF file.
 * @elf: file
 */
void cl_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - main function
 * @argc: umber of arguments
 * @argv: pointers to the arguments.
 *
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int open, read;

	open = open(argv[1], O_RDONLY);
	if (open == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read = read(o, header, sizeof(Elf64_Ehdr));
	if (read == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	ch_elf(header->e_id);
	printf("ELF Header:\n");
	p_magic(header->e_id);
	p_class(header->e_id);
	p_data(header->e_id);
	p_version(header->e_id);
	p_osabi(header->e_id);
	p_abi(header->e_id);
	p_type(header->e_ty, header->e_id);
	p_entry(header->e_en, header->e_id);

	free(header);
	close_elf(open);
	return (0);
}
