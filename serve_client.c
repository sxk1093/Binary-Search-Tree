#include <pthread.h>

pthread_rwlock_t lock = PTHREAD_RWLOCK_INITIALIZER;

void *downtime() {

	//Node* root = NULL;
	//printSubtree(root);
    Node* tempRoot;

	sleep(1);
        //TODO: 1st downtime: Do balanceTree here
    pthread_rwlock_wrlock(&lock);
    tempRoot = balanceTree(root);
    freeSubtree(root);
    root = tempRoot;
    pthread_rwlock_unlock(&lock);

    sleep(1);
        //TODO: 2nd downtime: Do balanceTree here
    pthread_rwlock_wrlock(&lock);
    tempRoot = balanceTree(root);
    freeSubtree(root);
    root = tempRoot;
    pthread_rwlock_unlock(&lock);

    sleep(1);
        //TODO: 3rd downtime: Do balanceTree here
    pthread_rwlock_wrlock(&lock);
    tempRoot = balanceTree(root);
    freeSubtree(root);
    root = tempRoot;
    pthread_rwlock_unlock(&lock);

    return NULL;
}


void* ServeClient(char *client){



	FILE *fptr;
	fptr = fopen(client,"r");
    char firstPart[100];
    int nodeInt;
    int sum;

    if(fptr == NULL)
        exit(1);

    while (fscanf(fptr, "%s %d", firstPart, &nodeInt) != EOF) {

	    if (strcmp(firstPart, "insertNode") == 0) {
            pthread_rwlock_wrlock(&lock);
            root = insertNode(root, nodeInt);
            printf("[%s]%s %d\n", client, firstPart, nodeInt);
            pthread_rwlock_unlock(&lock);
        }
        
        if (strcmp(firstPart, "deleteNode") == 0) {
            pthread_rwlock_wrlock(&lock);
            root = deleteNode(root, nodeInt);
            printf("[%s]%s %d\n", client, firstPart, nodeInt);
            pthread_rwlock_unlock(&lock);
        } 
        
        if (strcmp(firstPart, "sumSubtree") == 0) {
            pthread_rwlock_rdlock(&lock);
            sum = sumSubtree(root);
            printf("[%s]%s = %d\n", client, firstPart, sum);
            pthread_rwlock_unlock(&lock);
        }
        
        if (strcmp(firstPart, "countNodes") == 0) {
            pthread_rwlock_rdlock(&lock);
            sum = countNodes(root);
            printf("[%s]%s = %d\n", client, firstPart, sum);
            pthread_rwlock_unlock(&lock);

        }
        //fclose(fptr);


    }

     fclose(fptr);


	// TODO: Open the file and read commands line by line

	// TODO: match and execute commands

	// TODO: Handle command: "insertNode <some unsigned int value>"
	// print: "[ClientName]insertNode <SomeNumber>\n"
	// e.g. "[client1_commands]insertNode 1\n"

	// TODO: Handle command: "deleteNode <some unsigned int value>"
	// print: "[ClientName]deleteNode <SomeNumber>\n"
	// e.g. "[client1_commands]deleteNode 1\n"

	// TODO: Handle command: "countNodes"
	// print: "[ClientName]countNodes = <SomeNumber>\n"
	// e.g. "[client1_commands]countNodes 1\n"


	// TODO: Handle command: "sumSubtree"
	// print: "[ClientName]sumSubtree = <SomeNumber>\n"
	// e.g. "[client1_commands]sumSubtree 1\n"


	return NULL;
}
