#include <stdio.h>
#include <string.h>

int main(void) {
    char user_feedback[500];
    char modified_text[600] = {0};
    
    printf("Enter your feedback: ");
    if (fgets(user_feedback, sizeof(user_feedback), stdin) != NULL) {
        user_feedback[strcspn(user_feedback, "\n")] = '\0';
    }
    
    printf("Total characters: %zu\n", strlen(user_feedback));
    
    char *pos_good = strstr(user_feedback, "good");
    char *pos_bad = strstr(user_feedback, "bad");
    
    if (pos_good != NULL) {
        puts("Sentiment: Positive");
    } else if (pos_bad != NULL) {
        puts("Sentiment: Negative");
    } else {
        puts("Sentiment: Neutral");
    }
    
    if (pos_bad != NULL) {
        size_t prefix_len = pos_bad - user_feedback;
        
        strncpy(modified_text, user_feedback, prefix_len);
        modified_text[prefix_len] = '\0';
        
        strcat(modified_text, "not good");
        strcat(modified_text, pos_bad + 3);
        
        strcpy(user_feedback, modified_text);
        printf("Updated review: %s\n", user_feedback);
    }
    
    return 0;
}
