#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * structure composed by a tree (using the pointeirs left and right) and a list (using pointer next)
 */
typedef struct albero_{
	struct albero_ *left; //left node
	struct albero_ *right; //right node
	struct albero_ *next;// next node
	char visita; //flag to jnow if a nde has been visited
	char word[]; //word of the node
}albero_t;

albero_t *root; //root of the tree
albero_t* prec; //variable to know the precedent node of the list
int filter; //varibale to know if there is a game
int k; //size of the string
albero_t* start(int);
albero_t*  newNode(char*);
albero_t* inserisci_albero(albero_t*);
int nuova_partita(int, albero_t*);
int appartiene(char* word,albero_t* root,int k);
char* wordchecker(char*,char*,char*,int,int[][64],int*);
int asciif(char);
albero_t* inserisci_inizio(int);
void filtrate(int[][64],int,char*,int*,int*);
void resetta();
void visualizza_modified(albero_t*);
int strcmpa(char*,char*);
void left_rotate(albero_t*);
void right_rotate(albero_t*);


int main(){
	int k,n,j;
	filter=0;
	if(scanf("%d",&k))
			n=1;
	char word[k+1];
	root=start(k);
	j=0;
	while(filter==1){
		root=inserisci_inizio(k);
		if(scanf("%s",word));
		if(word[1]=='n')
			filter=0;
	}
//case of +inserisci_inizio before of the first +nuova_partita
	if(filter==0){
	while(n){
		if(n&&j>0)
			resetta();
		n=nuova_partita(k,root);
		if(n==2){
			root=inserisci_inizio(k);
      if(scanf("%s",word)){
				if(word[0]!='+')
					n=0;
				else
					n=1;
			}
		}
		j++;
	}
	}
}

/*
 * function that start the game
 * @param k (size of the strings)
*/
albero_t* start(int k){
	int flag;
	root=NULL;
	prec=NULL;
	char *word;
	albero_t* temp;
	word=(char*)malloc((k+1)*sizeof(char));
	flag=0;
	while(flag==0){
	  if(scanf("%s",word))
			word[k+1]='\0';
		if(word[0]=='+'){
			if(word[1]=='i')
				filter=1;
		  return root;
		}
		else{	
			temp=newNode(word);
			root=inserisci_albero(temp);
			prec=temp;
		}
	}
	return root;
}

/*
 * function that create a new node
 * @param chiave : word of the node
*/
albero_t* newNode(char chiave[]){
    albero_t *temp =malloc(sizeof(albero_t)+(k+1)*sizeof(char));
    strcpy(temp->word,chiave);
		temp->visita='1';
    temp->left = temp->right = NULL;
    return temp;
}

/*
 * function to add a node to the tree
 * @param z is the node to add
*/
albero_t *inserisci_albero(albero_t*z){
	albero_t *y;
	albero_t* x=root;
	y=NULL;
	while(x!=NULL){
		y=x;
		if(strcmpa(z->word,x->word)<0)
			x=x->left;
		else
			x=x->right;
	}
	if(y==NULL)
		root=z;
	else{
		if(strcmpa(z->word,y->word)<0)
			y->left=z;
		else
			y->right=z;
	}
  if(prec){
		prec->next=z;
	}
	return root;
}

/*
 * function that manage a new game
 * @param k size of the strings
 * @param root root of the tree
*/
int nuova_partita(int k,albero_t* root){

	albero_t* root2; //variable to memorize the value of root
	int flag,flag2,i,n,j;
	int p[k];
	char*rif,*esit;
	char word[k+1];
	int v[64];
	rif=(char*)malloc((k+1)*sizeof(char));
	int vinc[k][64];
	for(i=0;i<k;i++)
		for(j=0;j<64;j++)
			vinc[i][j]=1;
	for(i=0;i<64;i++)
		v[i]=k+1;
	if(scanf("%s",rif))
		flag=0;
	for(j=0;j<k;j++)
		p[j]=asciif(rif[j]);
	if(scanf("%d",&n))
	  flag2=0;
	i=0;
	esit=(char*)malloc((k+1)*sizeof(char));
	filter=0;
	while(flag==0){
		root2=root;
		if(scanf("%s",word))
			i=i+0;
		root=root2;
		if(word[0]=='+'){
			if(word[1]=='i'){
					root=inserisci_inizio(k);
					 filter=0;
					filtrate(vinc,k,rif,v,p);
						
			}else if(word[1]=='n'){
					return 1;
			}
			else{
				visualizza_modified(root);
			}
		}
		else{
			if(i==n){
				printf("ko\n");
					if(scanf("%s",word))
						flag=1;
					if(word[0]=='+'&&word[1]!='i')
						return 1;
					if(word[0]=='+'&&word[1]=='i'){
						return 2;
					}
					return 0;
				}
			else{
				if(appartiene(word,root,k)==1){
					 
						esit=wordchecker(esit,word,rif,k,vinc,v);
						flag2=1;
						for(j=0;j<k && flag2;j++){
							if(esit[j]!='+')
								flag2=0;
						}
						if(!flag2){
							printf("%s\n",esit);
							if(filter!=1){
								filter=0;
								filtrate(vinc,k,rif,v,p);
							}
							printf("%d\n",filter);
						}
						else{
							printf("ok\n");
							if(scanf("%s",word)){
								if(word[0]=='+'&&word[1]!='i'){
										return 1;
								}
								if(word[0]=='+'&&word[1]=='i'){
										return 2;
								}
								return 0;
							}
						}
						i++;
				}
				else{
					printf("not_exists\n");
				}
			}
			if(i==n){
					printf("ko\n");
					if(scanf("%s",word))
						flag=1;
					if(word[0]=='+'&&word[1]!='i')
						return 1;
					if(word[0]=='+'&&word[1]=='i'){
						return 2;
					}
					return 0;
				}
			
		
		}	
	}

	return 0;
}
	
/*
 * function for know if a word is in the tree (return 1 if is present, 0 otherwise)
 * @param word word to search in the tree
 * @param root root of the tree
 * @param k size of the strings
*/
int appartiene(char* word,albero_t* root,int k){
	albero_t* tmp;
	tmp=root;
	int p;
	while(tmp){
		p=strcmpa(word,tmp->word);
		
		if(p>0){
			if(tmp->right==NULL)
				return 0;
			tmp=tmp->right;
		}
		else if(p<0){
			if(tmp->left==NULL)
				return 0;
			tmp=tmp->left;
		}
		else
			return 1;
		
	}
	return 0;
}
/*
 * function to generate the string of comparisation of the words
 * @param esito string of comparisation
 * @param word word given by the user
 * @param rif word to guess
 * @param k size of the strings
 * @param vinc matrix for the constraint for the presence of the letters
 * @param v vector for the constraint for the order of the letters in the word
 * @return esito string of comparisation
*/

char* wordchecker(char* esito,char* word,char* rif, int k,int vinc[][64],int*v){
	
	 int i,j,ni,ki,ci,ascii,flag,flag2;
	 int arr[64];
	 for(j=0;j<64;j++)
		 arr[j]=0;
	 for(i=0;i<k;i++){
		ascii=asciif(word[i]);
		if(rif[i]==word[i]){
				for(j=0;j<64;j++)
					vinc[i][j]=0;
			vinc[i][ascii]=1;
			esito[i]='+';
			arr[ascii]++;
		 }
		 else{
			 vinc[i][ascii]=0;
			 flag=0;
			 flag2=0;
			 esito[i]='/';
			 ni=0;
			 ci=0;
			 ki=0;
			 for(j=0;j<k;j++){
					if(rif[j]==word[i]){
						esito[i]='|';
						ni++;
						flag=1;
				 }
					if(word[j]==word[i]){ 
						if(rif[j]==word[j]){
							ci++;
						}
					if(j<i&&rif[j]!=word[j])
						 ki++;
						}
			 }
			 if(ki>=(ni-ci)&&flag){
				 esito[i]='/';
				 v[ascii]=ni;
				 flag2=1;
			 }
			 if(!flag)
				 v[ascii]=0;
			 if(!flag2&&flag){
				 arr[ascii]++;
			 }
		 }
		 if(v[ascii]<0){
			 if(arr[ascii]>-v[ascii])
				 v[ascii]=-arr[ascii];
		 }
		 if(v[ascii]>k){
			if(arr[ascii]>=1){
        v[ascii]=-arr[ascii];
			}
		 }
		
	 }
	 
	 esito[k]='\0';
	return esito;
}

/**
 * function for tramutate the ascii in a new code of int
 * @param c character to change
 * @return  ascii int code
*/
int asciif(char c){
	int ascii=c;
	if(ascii>=48 && ascii<=57){
		  ascii=ascii-48;
			return ascii;
	}
		if(ascii==45){
			ascii=ascii-45+10;
			return ascii;
		}
		if(ascii==95){
			ascii=ascii-95+11;
			return ascii;
		}
		if(ascii>=65&&ascii<=90){
			ascii=ascii-65+12;
			return ascii;
		}
		if(ascii>=97&&ascii<=122){
			ascii=ascii-97+38;
			return ascii;

		}
		return ascii;
}

/*
 * function that manage "+inseriscic_inizio"
 * @param k size of string
 * @return root
*/
albero_t* inserisci_inizio(int k){
	int flag,j;
	j=0;
	char word[k+1];
	albero_t* temp;
	flag=0;
	while(flag==0){
	 
	  if(scanf("%s",word))
			word[k+1]='\0';
		if(word[0]=='+')
			flag=1;
		else{	
		  temp=newNode(word);	
			root=inserisci_albero(temp);
			prec=temp;
			j++;
		}
		
	}
  return root;
	
}

/*
 * function that filtrate the words of the tree and mark (with parameter visita ) if has been visited
 * @param vinc matrix for the constraint for the presence of the letters
 * @param v vector for the constraint for the order of the letters in the word
 * @param k size of string
 * @param rif word to guess
 * @param p word in the code of int (using function asciif)
 */
void filtrate(int vinc[][64],int k,char* rif,int*v,int* p){
	int flag;
	int i,count,g,l,s,count2;
  albero_t*tmp=root;
	while(tmp!=NULL){
		flag=1;
		if(tmp->visita=='1'){
		for(i=0;i<k&&flag;i++){
			l=asciif(tmp->word[i]);

			if(v[l]==0){
					flag=0;
					break;
				}	
			if(vinc[i][l]==0&&flag){
				flag=0;
				break;
			}
		  s=asciif(rif[i]);
			count=0;
			count2=0;
			for(g=0;g<k&&flag;g++){
					if(tmp->word[g]==rif[i])
						count++;
					if(tmp->word[g]==tmp->word[i])
						count2++;
				}
			if(flag&&v[s]<=k){
				if(count!=v[s]&&v[s]>0&&flag){
					flag=0;
					break;
				}
				if(count<-v[s]&&v[s]<0&&flag){
					flag=0;
					break;
				}
			}
			if(flag&&v[l]<=k){
				
				if(count2!=v[l]&&v[l]>0&&flag){
					flag=0;
					break;
				}
				if(count2<-v[l]&&v[l]<0&&flag){
					flag=0;
					break;
				}
			}
			
		}
		if(flag){
				filter++;
		}
		else
			tmp->visita='0';
		}
		tmp=tmp->next;
	}
}

/*
 * function to reset the param visita of the nodes to 0
*/
void resetta(){
	albero_t* tmp;
	tmp=root;
	while(tmp!=NULL){
		tmp->visita='1';
		tmp=tmp->next;
	}
}


/*
 * function to print the words (+stampa_filtrate)
 * @param root root of the tree
*/
void visualizza_modified(albero_t* root){
	if(root!=NULL){
		visualizza_modified(root->left);
		if(root->visita=='1'){
			printf("%s\n",root->word);
		}
		visualizza_modified(root->right);
		}else
			return;
}

/*
 * function that do the same thing of the strcmp() (implementated for the speed of the code)
*/
int strcmpa(char* word1,char*word2){
	int i;
	for(i=0;word1[i]!='\0';i++){
		if(word1[i]<word2[i])
			return -1;
		if(word1[i]>word2[i])
			return 1;
	}
	return 0;
}


		
