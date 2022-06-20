void uppercase(char * temp) {
  char * name;
  name = strtok(temp,":");

  char *s = name;
  while (*s) {
    *s = toupper((unsigned char) *s);
    s++;
  }

}
