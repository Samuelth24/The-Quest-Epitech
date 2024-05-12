/*
** EPITECH PROJECT, 2024
** kjhesd
** File description:
** kjhds
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 100
#define MAX_DEVICE_NAME_LENGTH 50
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_DEVICE_NAME_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} AuthorizedDevice;

AuthorizedDevice authorizedDevices[MAX_DEVICES];
int numDevices = 0;

bool isDeviceAuthorized(const char* deviceName, const char* username, const char* password)
{
    for (int i = 0; i < numDevices; i++) {
        if (strcmp(deviceName, authorizedDevices[i].name) == 0 &&
            strcmp(username, authorizedDevices[i].username) == 0 &&
            strcmp(password, authorizedDevices[i].password) == 0) {
            return true;
        }
    }
    return false;
}

void addDeviceToList()
{
    if (numDevices >= MAX_DEVICES) {
        printf("La liste blanche est pleine. Impossible d'ajouter un nouvel appareil.\n");
        return;
    }

    AuthorizedDevice newDevice;
    printf("Nom de l'appareil : ");
    fgets(newDevice.name, sizeof(newDevice.name), stdin);
    newDevice.name[strcspn(newDevice.name, "\n")] = '\0';

    printf("Nom d'utilisateur : ");
    fgets(newDevice.username, sizeof(newDevice.username), stdin);
    newDevice.username[strcspn(newDevice.username, "\n")] = '\0';

    printf("Mot de passe : ");
    fgets(newDevice.password, sizeof(newDevice.password), stdin);
    newDevice.password[strcspn(newDevice.password, "\n")] = '\0';

    authorizedDevices[numDevices] = newDevice;
    numDevices++;

    printf("L'appareil a été ajouté à la liste blanche.\n");
}

int main(int argc, char *argv[])
{
    while (1) {
        printf("\n=== Gestion de l'accès Wi-Fi ===\n");
        printf("1. Vérifier l'accès d'un appareil\n");
        printf("2. Ajouter un appareil à la liste blanche\n");
        printf("3. Quitter\n");
        printf("Choix : ");

        int choice;
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                char deviceName[MAX_DEVICE_NAME_LENGTH];
                char username[MAX_USERNAME_LENGTH];
                char password[MAX_PASSWORD_LENGTH];

                printf("Nom de l'appareil : ");
                fgets(deviceName, sizeof(deviceName), stdin);
                deviceName[strcspn(deviceName, "\n")] = '\0';

                printf("Nom d'utilisateur : ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = '\0';

                printf("Mot de passe : ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = '\0';

                if (isDeviceAuthorized(deviceName, username, password)) {
                    printf("Accès Wi-Fi autorisé pour l'appareil : %s\n", deviceName);
                } else {
                    printf("Accès Wi-Fi refusé pour l'appareil : %s\n", deviceName);
                }
                break;
            }
            case 2:
                addDeviceToList();
                break;
            case 3:
                printf("Au revoir !\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }
    return 0;
}
