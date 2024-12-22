#include<cstdio>
#include<cstdlib>
#include<ctime>
char a[10086][100];
bool b[26];
char *s[7]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
char *A[10]={"Calculus","English","Analysis","C++","Algebra","Python","Structure","Composition","Spirit","Drinking"};
void genblock(){
	int l=rand()%3+4,k;
	for(int i=0;i<l;++i){
		while(k=rand()%26,b[k]!=(i&1));
		putchar(k+(i?'a':'A'));
	}
}
void genname(){
	int s=rand()%2+2;
	while(s--){
		genblock();
		if(s)putchar(' ');
	}
}
int main(){
	b[0]=b['e'-'a']=b['i'-'a']=b['o'-'a']=b['u'-'a']=1;
	srand(time(0));
	int n=rand()%99+100;
	int m=rand()%9+10;
	freopen("public/students.csv","w",stdout);
	puts("id,name,age,sex");
	for(int i=1;i<=n;++i){
		printf("%d,",10000+i);
		genname();
		printf(",%d,%c\n",rand()%30+10,rand()%26+'A');
	}
	fclose(stdout);
	freopen("public/courses.csv","w",stdout);
	puts("stu_id,course_id,score");
	for(int i=1;i<=n;++i){
		printf("%d,",1000+i);
		printf("%s ",A[rand()%10]);
		genblock();
        printf(",%s %02d:%02d,",s[rand()%7],rand()%24,rand()%60);
        genname();
        printf(",%d-%03d",rand()%9+1,rand()%900+100);
		puts("");
	}
	fclose(stdout);
	freopen("public/scores.csv","w",stdout);
	puts("stu_id,course_id,score");
	for(int i=0;i<n;++i)
	for(int j=0;j<m;++j)if(rand()%1000<600)
		printf("%d,%d,%d\n",10000+i,1000+j,rand()%201-100);
	fclose(stdout);
	return 0;
}
