#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

int main(int argc,char *argv[]){
    DIR *dirp = opendir(argv[1]);
    struct dirent *dp;
    struct stat st;
    char startdir[256];
    getcwd(startdir,sizeof(startdir));
    long buckets[12]={0,0,0,0,0,0,0,0,0,0,0,0};
    long numFiles =0;
    chdir(argv[1]);
    do {dp = readdir(dirp);
        if(dp==NULL){continue;}
        if(strcmp(dp->d_name,".")==0 || strcmp(dp->d_name,"..")==0){continue;}
        stat(dp->d_name,&st);
        numFiles++;
        long s = (long)st.st_size;
        for(long i =0;i<13;i++){
            if(s<pow(10,i)){
                buckets[i]++;
                break;}}
    }while(dp!=NULL);
    printf("\n");
    int normalised[12];
    for(int i=0;i<12;i++){normalised[i]=50*buckets[i]/numFiles;}
    for(int i =0;i<10;i++){
        printf("10^%d %d \t|%.*s>\n",i,buckets[i],normalised[i],"=============================================");
    }
    chdir(startdir);
    return 0;
}
