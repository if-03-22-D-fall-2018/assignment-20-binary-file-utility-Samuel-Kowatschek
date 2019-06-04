#include <stdio.h>

#define len 64

int main(int argc, char const *argv[]) {
  int age;

  FILE* fd=fopen("student.dat","r");
  int id;

  fseek(fd,0,SEEK_SET);
  fseek(fd,sizeof(int),SEEK_SET);
  printf("%10s %-32s %-32s %-3s\n", "Id","First Name","Last Name","Age");
  int count = fread(&id,sizeof(int),1,fd);
  char first_name[len];
  char last_name[len];
  while (count > 0) {
    fread(first_name,sizeof(first_name),1,fd);
    fread(last_name,sizeof(last_name),1,fd);
    fread(&age,sizeof(int),1,fd);
    count = fread(&id,sizeof(int),1,fd);
    printf("%010d %-32s %-32s %-3d\n", id, first_name, last_name, age);
  }
  fclose(fd);
  return 0;
}
