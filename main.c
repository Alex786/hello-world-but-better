#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void) {
	// amount of characters to read from stdin
	uint8_t char_limit = 10;

	// Allocate memory for the buffer to hold the input string + 1 for \0
	char* buffer = malloc((char_limit + 1) * sizeof(char));
	
	// check if malloc failed to allocate memory such as when the system is out of memory
	if (buffer == NULL) {
		fprintf(stderr, "Error: Failed to allocate memory\n");
		
		// Return failure status
		return EXIT_FAILURE;
	}

	// Prompt the user for input and read a string from stdin
	printf("Enter your first name: ");

	// Read input from stdin with a limit of char_limit characters
	if (fgets(buffer, char_limit + 1, stdin) != NULL && strlen(buffer) > 0) {
        // Remove the trailing newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';
    } else {
		fprintf(stderr, "Error: Failed to read input\n");
		free(buffer);
		return EXIT_FAILURE;
	}

	// Print the greeting message with the user's input
	printf("Hello %s!\n", buffer);

	// Free the allocated memory for the buffer
	free(buffer);

	// Return success status
	return EXIT_SUCCESS;
}