#include <stdio.h>
#include <stdlib.h>
//#include <fun.h>

int main(int argc ,char *argv[])
{
	while(1)
	{



		int cmd=0;
		print_help();
		printf("Ingrese las instrucciones:");
		scanf("%d",&cmd);



		if(cmd==1)
		{
			char dest_file[31]="";
			char src_file[31]="";
			unsigned long file_length=0;
			char  *read=NULL;
			unsigned int password=0;
			// Obtener el archivo de origen y el nombre del archivo de destino del teclado
			get_file_name(dest_file,src_file);

			// Leer el contenido del archivo

			read = read_src_file(&file_length,src_file);
			// Obtener contraseña encriptada
			printf("Por favor, introduzca su contraseña:");
			scanf("%u",&password);
			// Cifrado de matriz de caracteres
			read=file_text_encrypt(read,file_length,password);

			// guardar documento
			save_file(read,file_length,dest_file);


		}
		else if (cmd==2)
		{
			char dest_file[31]="";
			char src_file[31]="";
			unsigned long file_length=0;
			char  *read=NULL;
			unsigned int password=0;
			// Obtener el archivo de origen y el nombre del archivo de destino del teclado
			get_file_name(dest_file,src_file);

			// Leer el contenido del archivo

			read = read_src_file(&file_length,src_file);
			// Obtener contraseña encriptada
			printf("Por favor, introduzca su contraseña:");
			scanf("%u",&password);
			// Cifrado de matriz de caracteres
			read=file_text_decrypt(read,file_length,password);


			// guardar documento
			save_file(read,file_length,dest_file);

		}
		else if (cmd==3)
		{
			break;
		}
		else
		{
			printf("Se produjo un error en el comando de entrada !!! \ n");
		}


	}

	return 0;
}
