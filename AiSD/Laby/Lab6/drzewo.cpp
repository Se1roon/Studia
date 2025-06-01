#include <cstdlib>
#include <iostream>

using namespace std;

struct node {
	int key;
	int count;
    node *l;
    node *r;
    node(int x) { key=x; count=1; }
};

typedef node *link;
link head, guard;

void look_put(int x, link& h) {
	if(x < h->key) look_put(x,h->l);
    else if(x > h->key) look_put(x,h->r);
	else if(h != guard) h->count++;
    else {
		h=new node(x);
		h->l=guard;
        h->r=guard;
    }            
}
 
int look(int x, link h) {
	cout << h->key << endl;

    if(x < h->key) look(x,h->l);
    else if(x > h->key) look(x,h->r);
    
	return h != guard ? 1 : 0;
} 
    
void writetree(link h, int k) {
	if(h == guard) return;
	
	writetree(h->l,k+1);
	for(int i = 0; i < k; i++)
		cout <<"  ";
	cout << h->key << "(" << h->count << ")" << endl;
	writetree(h->r,k+1);
}

int zliczxy(int x, int y, link h) {
	if (h == guard) return 0;

	return (x <= h->key && h->key <= y) ? h->count + zliczxy(x, y, h->l) + zliczxy(x, y, h->r) :
		zliczxy(x, y, h->l) + zliczxy(x, y, h->r);
}


int main(int argc, char *argv[]) {
	int i;
	int x;
	
	guard=new node(0);

	cout <<"podaj 1 klucz"<<endl;
	cin>>x;
 
	head=new node(x);
	head->l=guard;
	head->r=guard;

	for(i=0;i<10;i++) {
		cout<<"podaj klucz"<<endl;
        cin>>x;
        guard->key=x;
        look_put(x,head);
    }

	cout << "drzewo o korzeniu = " << head->key << endl;  
	writetree(head,0);

	do {
		cout << "podaj x" << endl;
		cin >> x;
		guard->key = x;

		if(look(x,head) == 1) cout << "jest" << endl;
		else cout << "nie ma" << endl;
	} while (x != -1);

	int xx, yy;
	cout << "x y: ";
	cin >> xx >> yy;

	cout << "x = " << xx << "  y = " << yy << '\n';
	cout << "ilosc = " << zliczxy(xx, yy, head) << '\n';
    
// system("PAUSE");
	return EXIT_SUCCESS;
}

