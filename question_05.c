#include<stdio.h>
#include<string.h>
//function prototype

void encodeMessage(char message[]);
void decodeMessage(char message[]);
void toggleBits(char *ch);

int main(){
    char message[200];
    int choice;
    int i=0;


    while(1){
        printf("---TCS secure messaging tool---\n");
        printf("1. encode message\n");
        printf("2. decode message\n");
        printf("3. exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        getchar();
        switch (choice)
        {
        case 1:
            printf("enter message to encode:");
            fgets(message,sizeof(message),stdin);
            message[strcspn(message, "\n")] = '\0';
            encodeMessage(message);
            break;
        case 2:
            printf("enter message to decode:");
            fgets(message,sizeof(message),stdin);
            message[strcspn(message, "\n")] = '\0';
            decodeMessage(message);
            break;
        case 3:
            printf("exiting program......");
            return 0;
        
        default: printf("invalid choice");
            break;
        }
    }
    return 0;
}

//function definition

void toggleBits(char *ch){
    *ch ^= (1<<1);
    *ch ^= (1<<4);
}
void encodeMessage(char message[]){
    int l = strlen(message);
    char encoded[200];
    //reverse string
    for(int i=0 ;i<l ;i++){
        encoded[i] = message[l-i-1] ;
    }
    encoded[l]='\0' ;
    //toggle bit 
    for(int i=0 ;i<l ;i++){
        toggleBits(&encoded[i]);
    }
    printf("encoded message is: %s\n",encoded);
}
void decodeMessage(char message[]){
    int l = strlen(message);
    char decode[200];
    //remove toggle
    char decoded[200];
    for(int i=0 ;i<l ;i++){
        decoded[i] = message[i] ; 
        toggleBits(&decoded[i]);
    }
    //string reversal
    char final[200];
    for(int i=0 ;i<l;i++){
        final[i] = decoded[l-i-1] ;
    }
    final[l] ='\0';
    printf("the decoded message is:%s\n",final);

}