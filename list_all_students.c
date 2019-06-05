#include <stdio.h>

#define len 64

int main(int argc, char const *argv[]) {
  
  int age;
  char first_name[len];
  char last_name[len];
  int id;
  FILE* fd = fopen("student.dat", "r");
  //go to the first student

  fseek(fd, 0, SEEK_SET);
  fseek(fd, sizeof(int), SEEK_SET);
  
  printf("%10s %-20s %-20s %10s\n", "Id", "First Name", "Last Name", "Age");

  int count = fread(&id, sizeof(int), 1, fd);
  while(count > 0)
  {
    fread(first_name, sizeof(first_name), 1, fd);
    fread(last_name, sizeof(last_name), 1, fd);
    fread(&age, sizeof(age), 1, fd);
    printf("%-10d %-20s %-20s %10d\n", id, first_name, last_name, age );
    count = fread(&id, sizeof(int), 1, fd);
  }
  fclose(fd);
  return 0;
}