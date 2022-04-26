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

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

#define ANSI_COLOR_RESET   "\x1b[0m"

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
                     "    .:::JY~.:?Y?:.^JJ!..7J?:::::::.:..  \n"
                     "    .::~!!!!!!!!!?7??777???~:::...      \n"
                     "    :::YPPPPPPPPG@@@@@@@@@@G:::         \n"
                     "    :::~~~~~~~~~~!!!!!!!!!!~:::         \n"
                     "    ...........................\n"
                     "      ========SHELL-ITA======== \n"
                     "   Benjamin Mosso and Felipe Rodriguez  \n \n"
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
        //printf("%i \n", errno);

        if (errno == ENOENT){
            printf ("El enlace nombrado por oldpath no existe; o, un directorio el componente en newpath no existe; o, viejo camino o newpath es una cadena vacía. \n");
        }else if (errno == EFAULT){
            printf ("oldpath o newpath puntos fuera de su dirección accesible espacio. \n");
        } 
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
        //printf("%i \n", errno);
    }
    else if (strcmp (command, "changename")== 0 ) //validacion de llamada al sistema
    {
    
        rename(tokens[1], tokens[2]);
        if (errno == ENOENT){
            printf ("El enlace nombrado por oldpath no existe; o, un directorio el componente en newpath no existe; o, viejo camino o newpath es una cadena vacía. \n");
        }else if (errno == EFAULT){
            printf ("oldpath o newpath puntos fuera de su dirección accesible espacio. \n");
        }
    }
    else if(strcmp (command, "color")==0) // funcionalidad extra, cambio de color
    {
        int color=0;
        
        if (strcmp (tokens[1], "rojo")== 0)
        {
            color=1;

        }else if ((strcmp (tokens[1], "verde")== 0))
        {
            color=2;
        }else if (strcmp (tokens[1], "azul")== 0)
        {
            color=3;
        }else if (strcmp (tokens[1], "default")== 0)
        {
            color=4;
        }
        printf("%d \n", color);

        switch (color)
        {
        case 1:
            printf( ANSI_COLOR_RED "el texto es color ROJO!\n");
            break;
        case 2:
            printf( ANSI_COLOR_GREEN "el texto es color VERDE!\n");
            break;
        case 3:
            printf( ANSI_COLOR_BLUE "El texto es color AZUL!\n");
            break;
        case 4:
            printf( ANSI_COLOR_RESET "el texto vuelve a sus colores default!\n");
            break;
        default:
            break;
        }
    } 
    else if(strcmp (command, "Salir")== 0) //validacion de salida
    {
        printf("\n");
        
    }else{
        printf("ingrese una llamada al sistema valida \n"); //mensaje de error en caso de que no se ingrese algo congruente
        }

    } while ( strcmp(command, "Salir") !=0 );

    char *despedida  = "\033[92m"
                     "\n"
                     "      ........................         \n"
                     "    ............................        \n"
                     "    .:^~!!!!!!!!!!!!!!!!!!!~^:.::.      \n"
                     "    :::J555555555Y555555555?.:::.....   \n"
                     "    :::J55?^~Y5Y~^755?^^J55?.!J?55!:::. \n"
                     "    :::J55!  J5Y:  557  ?557.^~~7P@P::: \n"
                     "    :::?55!  J5Y:  557  ?557::::.:B@~::.\n"
                     "    :::755!  J5Y:  557  ?55!::::::B@~::.\n"
                     "    .::755!  J5Y:  557  ?55!::::::B@~::.\n"
                     "    .::!55!  J5Y:  557  ?55~::::::B@~::.\n"
                     "    .::!55!  J5Y:  557  ?55~::::::B@~::.\n"
                     "    .::~55!  J5Y:  557  ?55^::::::B@~::.\n"
                     "    .::~55!  J5Y:  557  ?55^:::::.B@~::.\n"
                     "    .::^55!  J5Y:  557  ?5Y^:^^^^J@B:::.\n"
                     "    .::^55!  JPY:  557  PY:~JJJPBJ^::. \n"
                     "    .:::JY~..?Y?:.^JJ!..7J?:::::::.:..  \n"
                     "    .::~!!!!!!!!!?7??777???~:::...      \n"
                     "    :::YPPPPPPPPG@@@@@@@@@@G:::         \n"
                     "    :::~~~~~~~~~~!!!!!!!!!!~:::         \n"
                     "    ...........................\n"
                     "      ========SHELL-ITA======== \n"
                     "   Benjamin Mosso and Felipe Rodriguez  \n \n"
                     "\033[0m";

                     printf("Se termino la Shell-ita \n %s",despedida);


    return 0;
}