bool isPalindrome(int x){
    int original = x;  // Store the original number
    long int reversed = 0, remainder;
    if(x < 0){
        return false;
    }
    while (x != 0) {
        remainder = x % 10;          
        reversed = reversed * 10 + remainder; 
        x /= 10;  
    }
    if (original == reversed) {
        return true; // It's a palindrome
    } else {
        return false; // It's not a palindrome
    }
      
}