#include <stdio.h>
#include "fleamarket.h"
#define N 100

void listCategory(){    //전체 카테고리를 보여주는 함수
        printf("\n-------------------------------------------------\n");
        printf("                 CATEGORIES\n");
        printf("-------------------------------------------------\n");
        printf("clothes         shoes     accessories electronics\n");
        printf("furnitures      living    books       tickets\n");
        printf("-------------------------------------------------\n");
}

int createProduct(Product *p){    //제품명, 판매가격, 카테고리, 아이디, 중고상품여부를 만들기 위한 함수
        getchar();
        printf("회원님의 아이디를 입력하세요 : ");
        scanf("%[^\n]s", p->id);
        printf("등록할 제품 이름을 입력하세요 : ");
        getchar();
        scanf("%[^\n]s", p->name);
        printf("제품의 판매 가격을 입력하세요 : ");
        scanf("%d", &p->price);
        listCategory();
        printf("제품의 카테고리를 입력하세요 : ");
        getchar();
        scanf("%[^\n]s", p->category);
        printf("제품이 중고 상품이라면 0, 새 상품이라면 1을 입력해 주세요 : ");
        scanf("%d", &p->used);
        printf("\n제품이 등록되었습니다!\n");
        return 1;

}


void readProduct(Product p){     //1개의 제품을 나열하기 위한 함수
        printf(" %s %5d %s %d %s\n", p.name, p.price, p.category, p.used, p.id);
}


int updateProduct(Product *p){    //제품을 수정하기 위한 함수
        getchar();
        printf("\n회원님의 아이디를 입력하세요 : ");
        scanf("%[^\n]s", p->id);
        printf("등록할 제품 이름을 입력하세요 : ");
        getchar();
        scanf("%[^\n]s", p->name);
        printf("제품의 판매 가격을 입력하세요 : ");
        scanf("%d", &p->price);
        listCategory();
        printf("제품의 카테고리를 입력하세요 : ");
        getchar();
        scanf("%[^\n]s", p->category);
        printf("제품이 중고 상품이라면 0, 새 상품이라면 1을 입력해 주세요 : ");
        scanf("%d", &p->used);
        printf("\n제품정보가 수정되었습니다!!\n");
        return 1;
}
int deleteProduct(Product *p){    //제품을 삭제하기 위한 함수
        p->price = -1;
        //p->name = "deleted";
        //p->id = "deleted";
        //p->category = "deleted";
        p->used = -1;
<<<<<<< HEAD
	return 0;
=======
	return 1;
>>>>>>> e195ebf0d0ed6cb953e76eae7a18c32ef675c39c
}

int selectDataNo(Product *p, int count){    //수정하거나 삭제할 제품의 번호를 입력받는 함수
        int no;
        listProduct(p, count);
        printf("제품의 번호를 입력해주세요: (취소:0)");
        scanf("%d", &no);
        return no;
}

int selectMenu(){    //전체 메뉴를 보여주는 함수
        int menu;
        printf("*********메뉴**********\n");
        printf("1. 등록된 중고 제품  조회\n");
        printf("2. 중고 제품 추가\n");
        printf("3. 중고 제품 정보 수정\n");
        printf("4. 중고 제품 삭제\n");
        printf("5. 검색\n");
        printf("6. 후기 게시판\n");
        printf("7. 제품 파일 저장\n");
        printf("8. 아이디 저장\n");
        printf("9. 작성한 후기 저장\n");
        printf("0. 종료하기\n");
        printf("***********************************\n\n");
        printf("원하는 메뉴의 번호를 입력해주세요 :  ");
        getchar();
        scanf("%d", &menu);
        return menu;
}

void listProduct(Product *p, int count){  //제품 나열을 하기 위한 함수
        printf("\nNo 제품명  판매가격  카테고리  중고상품 여부(0:중고, 1:새상품)  판매자 id\n");
        printf("===========================================\n");
        for(int i=0;i<count;i++){
                if(p[i].price == -1) continue;
                printf("%2d", i+1);
                readProduct(p[i]);
        }
        printf("\n");
}


void saveProduct(Product *p, int count){   //제품 데이터 저장하기 위한 함수
    FILE *fp;

    fp = fopen("product.txt", "wt");

    for(int i=0;i<count;i++){
        if(p[i].price!= -1)
            fprintf(fp, "%s\n%d %s\n%d %s\n",
                        p[i].name, p[i].price, p[i].category, p[i].used, p[i].id);
    }
    printf("파일에 저장되었습니다!\n");
        fclose(fp);
}

int loadProduct(Product *p){     //제품 데이터 불러오기 위한 함수
    int count = 0;

    FILE *fp;
    fp = fopen("product.txt", "rt");
    if(fp==NULL){
        printf("=> 파일이 없습니다.\n");
        return 0;
    }
    for(;;count++){
        //fscanf(fp, "%[^\n]s %d %[^\n]s %d %[^\n]s ",
                        //p[count].name, &p[count].price, p[count].category,&p[count].used, p[count].id);
        char c = 's';
        fscanf(fp, "%[^\n]s", p[count].name);
        fscanf(fp, "%d", &p[count].price);
        fscanf(fp, "%[^\n]s", p[count].category);
        fscanf(fp, "%d", &p[count].used);
        fscanf(fp, "%[^\n]s", p[count].id);
        fscanf(fp, "%c", &c);
        if(feof(fp)) break;
    }
    fclose(fp);
    printf("=>등록된 제품을 로딩하였습니다.\n");
    return count;
}

/*void Search(Product *p, int count){
        int choice;
        printf("\n1. 이름 검색\n");
        printf("2. 가격 검색\n");
        printf("3. 카테고리 검색\n");
        printf("검색 종류 선택 : ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
        searchName(p[], couunt); break;
        case 2:
        searchPrice(p[],count); break;
        case 3:
        searchCategory(p[],count); break;
        }
}

void searchName(Product *p, int count){
        char name[100];
        int i = 0;
        printf("검색 할 이름 : ");
        scanf("%d",name);
        for( i = 0; i < count; i++){
                if(name == p[i]->name)
                        listProduct(p);
        }
        return;
}

void searchPrice(Product *p, int count){

}

void searchCategory(Product *p, int count){

}*/


int ID(int ID_count){
        int answer;
        printf("아이디가 있으십니까? (예:1, 아니오: 0)");
        scanf("%d",&answer);
        return answer;
}

void SaveData_Member(Data *data, int ID_count){
        FILE *fp;
        fp = fopen("Member.txt","wt");
        for(int i=0; i<ID_count; i++){
        fprintf(fp,"%s ",data[i].idid);
        }
        fclose(fp);
        printf("=> 아이디 저장 완료하였습니다.\n");
}

int LoadData_Member(Data* data){
        int i = 0;
        FILE *fp;
        fp = fopen("Member.txt","rt");
        if(fp == NULL){
                printf("=> 아이디 파일이 없습니다.\n");
                 return 0;
        }
        while(1){
                fscanf(fp,"%s",data[i].idid);
                i++;
                if(feof(fp)) break;
        }
        fclose(fp);
        printf("=> 아이디 파일 로딩완료하였습니다.\n");
        return i;
}
int ReviewBoard(Data *data, int count){
        int a;
        printReview(data,count);
        printf("후기를 남기시겠습니까? (예: 1, 아니오 : 0)");
        scanf("%d",&a);
        return a;
}

void printReview(Data* data,int count){
        int i=0;
        printf("\n======================\n");
        for(i=0; i<count ; i++){
                printf("%d. %s\n",i+1, data[i].review);
        }
        printf("======================\n");
}

void SaveData_Review(Data* data, int Review_count){
        FILE *fp;
        fp = fopen("Review.txt","wt");
        for(int i=0; i<Review_count; i++){
        fprintf(fp,"%s",data[i].review);
        }
        fclose(fp);
        printf("리뷰 저장완료하였습니다.\n");
}

int LoadData_Review(Data* data){
        int i =0;
        FILE *fp;
        fp = fopen("Review.txt","rt");
        if(fp == NULL){
                printf("=> 후기 파일이 없습니다.\n");
        return 0;
        }
        while(1){
                fscanf(fp,"%[^\n]s",data[i].review);
                i++;
                if(feof(fp)) break;
        }
        fclose(fp);
        printf("리뷰를 로딩하였습니다.\n");
        return i;
}

