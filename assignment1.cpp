#include <bits/stdc++.h>
using namespace std;

class item{
    public:
    int item_no, profit, weight;
    float ppw, selected;
    item(int it, int pro, int wei){
        item_no = it, profit = pro, weight = wei;
        ppw = (float)pro/wei;
        selected = 0;
    }
};

void sort_ppw(vector<item>&items){
    for(int i=0; i< items.size()-1; i++){
        for(int j=0;j<items.size()-1;j++){
            if(items[j].ppw<items[j+1].ppw){
                item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
    return;
}

void select_items(vector<item>&items, int max_weight){
    int available_weight = max_weight;
    for(int i=0;i<items.size();i++){
        if(available_weight-items[i].weight >= 0){
            items[i].selected = 1;
            available_weight-=items[i].weight;
        }else{
            items[i].selected =(float) available_weight/items[i].weight;
            return;
        }
    }
    return;
}

int main(){
    vector<item> items;
    int total_items;
    int capa;
    cout<<"Enter total no. of items\n";
    cin>>total_items;
    cout<<"Enter weight capacity\n";
    cin>>capa;
    for(int i=0;i<total_items;i++){
        int item_no, profit, weight;
        cout<<"Enter item number\n";
        cin>>item_no;
        cout<<"Enter profit\n";
        cin>>profit;
        cout<<"Enter weight\n";
        cin>>weight;
        item temp = item(item_no, profit, weight);
        items.push_back(temp);
    }

    sort_ppw(items);
    select_items(items, capa);
    float total_profit = 0;
    for(int i=0;i<items.size();i++){
        cout<<"Item no. -> "<<items[i].item_no<<"\nSelected amount -> "<<items[i].selected<<endl;
        total_profit+=items[i].profit*items[i].selected;
    }
    cout<<"\nTotal profit -> "<<total_profit<<endl;

    return 0;
}