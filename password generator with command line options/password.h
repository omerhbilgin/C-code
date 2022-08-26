#ifndef PASSWORD_H
#define PASSWORD_H

// This functions generates a password of specified length
// and copies it into the given string
// charset 1 --> only letters (lower & upper)
// charset 2 --> alphanumeric (letters + numbers)
// charset 3 --> complex charset
void makePasswd (char *string, int length, int charset);  

#endif // PASSWORD_H
