#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    // Counts the number of arguements in the command line
    if (argc == 2)
    {
        // Converts index 1 of argv to an int
        const int KEY = atoi(argv[1]);
        // Stores a boolean to use as an off switch if we dectect a bad input
        bool isKeyValid = true;
        // Stores the length of the the string in index 1 of the argv array
        int len = strlen(argv[1]);    
        // Loop that checks each digit to see if it's a number
        for (int i = 0; i < len; i++)
        {
            // If isdigit detects a non-digit it'll set our stored bool to false and end the loop
            if (isdigit(argv[1][i]) == false)
            {
                isKeyValid = false;
                i = len;
            }
        }
        // If the loop successfully finishes and the isKeyValid bool stays true then we have a valid key and can proceed
        if (isKeyValid)
        {
            
            string plain = get_string("plaintext: ");
            int plainLength = strlen(plain);

            for (int i = 0; i < plainLength; i++)
            {
                if (isupper(plain[i]))
                {
                    if (plain[i] + KEY >  'Z')
                    {
                        int keyRemainder = (plain[i] + KEY) - 'Z';
                        if (keyRemainder > 'Z' - 'A')
                        {
                            while (keyRemainder >= ('Z' - 'A'))
                            {
                                keyRemainder = keyRemainder - ('Z' - 'A');
                            }
                            if (plain[i] + keyRemainder > 'Z')
                            {
                                keyRemainder = plain[i] + keyRemainder - 'Z';
                                plain[i] = 'A' + keyRemainder - 1;
                            }
                            else
                            {
                                plain[i] = 'a' + keyRemainder - 1;  
                            }
                        }
                        else
                        {
                            plain[i] = 'A' + keyRemainder - 1;
                           
                        }
                    }
                    else if (plain[i] + KEY <= 'Z')
                    {
                        plain[i] = plain[i] + KEY;
                    }
                }
                if (islower(plain[i]))
                {
                    if (plain[i] + KEY >  'z')
                    {
                        // Takes the value of our selected letter and adds total steps then subtracts 'z' to take it down a whole rotation of the wheel
                        int keyRemainder = (plain[i] + KEY) - ('z');
                        // Checks to see if the left over amount of steps is still greater than the value of the entire length of the alphabet
                        if (keyRemainder >= 'z' - 'a')
                        {
                            // While the keyRemainder is greater than 25 we continue this loop
                            while (keyRemainder >= ('z' - 'a'))
                            {
                                // Each iteration subtracts 26 "length of the alphabet" from the                                         total
                                keyRemainder = keyRemainder - (26);
                            }
                                    
                            // If the initial letter value + the new remainder is still greater than z, we do one last wrap a round by taking the difference and adding it to the value of 'a'.
                            if (plain[i] + keyRemainder > 'z')
                            {
                                keyRemainder = plain[i] + keyRemainder - 'z';
                                plain[i] = 'a' + keyRemainder - 1;
                            }
                            // If the keyRemainder + the initial letter value is not greater than 'z' than we take the initial letter value and add the number of steps left in the keyRemainder
                            else
                            {
                                plain[i] = 'a' + keyRemainder - 1;  
                            }
                        }
                        else
                        {
                                plain[i] = 'a' + keyRemainder - 1;
                        }
                    }
                    else if (plain[i] + KEY <= 'z')
                    {
                        plain[i] = plain[i] + KEY;
                    }
                }                        
            }
            
            
            printf("ciphertext: %s\n", plain);
        }
        // If we detected an unusable key we ask for a proper key
        else
        {
            printf("Usage: ./caesar key\n");
        }
        
    }
    // If too many arguements were entered then we ask for a proper key
    else if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        printf("1");
        return (1);
    }

}
