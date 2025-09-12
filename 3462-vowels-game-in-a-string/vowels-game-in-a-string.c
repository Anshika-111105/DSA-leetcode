bool doesAliceWin(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true; // Alice wins if any vowel exists
        }
    }
    return false; // no vowels, Alice loses
}