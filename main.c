#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
//definimos tamaño de arreglos
#define sizecmd 1024

int main() {
    //declaracion de variables
    char command[sizecmd];
    char *tokens[sizecmd];
    char *bienvenida  = "\033[92m"
                     "\n"
                     "     .......   .  .......             \n"
                     "    ..:.:~!~^....:...:~!!^.:...         \n"
                     "  .::^^7B@@@#J~JPG577B@@@&Y^^:::.       \n"
                     " :::Y&&@@@@@@@@@@@@@@@@@@@@&&#J:::      \n"
                     " :::Y&&&######&############&&#J:::      \n"
                     "  .:.:^~!!!!!!!!!!!!!!!!!!!~^:.::.      \n"
                     "   .:::J555555555Y555555555?.:::.....   \n"
                     "    :::J55?^~Y5Y~^755?^^J55?.!J?55!:::. \n"
                     "    :::J55!.:J5Y:.~557..?557.^~~7P@P::: \n"
                     "    :::?55!::J5Y::~557.:?557::::.:B@~::.\n"
                     "    :::755!::J5Y::~557.:?55!::::::B@~::.\n"
                     "    .::755!::J5Y::~557.:?55!::::::B@~::.\n"
                     "    .::!55!::J5Y::~557.:?55~::::::B@~::.\n"
                     "    .::!55!::J5Y::~557.:?55~::::::B@~::.\n"
                     "    .::~55!::J5Y::~557.:?55^::::::B@~::.\n"
                     "    .::~55!::J5Y::~557.:?55^:::::.B@~::.\n"
                     "    .::^55!::J5Y::~557.:?5Y^:^^^^J@B:::.\n"
                     "    .::^55!::JPY::~557.:?PY:~JJJPBJ^::. \n"
                     "    .:::JY~.:?Y?:.^JJ!..7J?:::::::.:..  \n"
                     "    .::~!!!!!!!!!?7??777???~:::...      \n"
                     "    :::YPPPPPPPPG@@@@@@@@@@G:::         \n"
                     "    :::~~~~~~~~~~!!!!!!!!!!~:::         \n"
                     "    ...........................\n\n"
                     "      ========SHELL-ITA======== \n"
                     "\033[0m";
    printf("%s", bienvenida);
    printf("Escribe 'Salir' para salir.\n\n");


    do {
        printf("shell-ita $~ ");
        fgets(command, sizecmd, stdin); //ingreso de llamadas al sistema
        command[strlen(command) - 1] = '\0';

        char *token = strtok(command, " ");
        int i = 0;
        if(token != NULL){
            while(token != NULL){       //separamos la llamada al sistema del argumento
                tokens[i] = token;
                token = strtok(NULL, " ");
                i++;

            }
         }

    if (strcmp (command, "createdir") == 0 ) //validacion de llamada al sistema
       {
        mkdir(tokens[1], 0755);         //llamada mkdir alias createdir
        printf("%i \n", errno);
    }

    else if (strcmp (command, "listar")== 0) //validacion de llamada al sistema
    {
        struct stat statArchivo;
        struct dirent *entr;
        DIR *directorio=opendir (".");
        entr = readdir(directorio);

        do {
            printf("%s ", entr->d_name);
        } while ((entr = readdir(directorio)) != NULL);
        
        printf("\n");
        printf("%i \n", errno);
    }
    else if (strcmp (command, "changename")== 0 ) //validacion de llamada al sistema
    {
    
        rename(tokens[1], tokens[2]);
        if (errno == ENOENT){
            printf ("El enlace nombrado por oldpath no existe; o, un directorio el componente en newpath no existe; o, viejo camino o newpath es una cadena vacía.");
        }else if (errno == EFAULT){
            printf ("oldpath o newpath puntos fuera de su dirección accesible espacio.");
        }
    }
    else if (strcmp (command, "Salir")== 0) //validacion de salida
    {
        printf("\n");
        
    }else {
        printf("ingrese una llamada al sistema valida \n"); //mensaje de error en caso de que no se ingrese algo congruente
        }

    } while ( strcmp(command, "Salir") !=0 );

    return 0;
}