//Project1 creating the twitter tweeter
//first step is to parse data and place it in an array (of size 280 chars)
//second step is to use the markovian chain algorithm on the array
//markov property only depends on where i am now and not the past.
//treat every word as a state and predict the next word based on the previous state
//when a word is added, have to add one to total for that pair and add 
//one to the word appearing next based on the prev state and then divide by the 
//total to get the percentage that that word will be next
//third step is to spit out your own tweet no greater than 280 characters


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <time.h>
using namespace std;

//typedef pair<string,string> strPair;


int main(){
	//typedef vector<string> vecString;
  srand(time(NULL));
	
	multimap<pair<string,string>, pair<string,double>> markovMMap;
	//multimap<strPair, string> markovMMap;
	int i=0;
	//vector<string> tweetVect;
	string tweetArr[280];
	ifstream file;
	ofstream outFile;
	file.open("tweet2.txt");

	while(file){
		file >> tweetArr[i];
		if(i>1){
			markovMMap.insert(make_pair(make_pair(tweetArr[i-2],tweetArr[i-1]),make_pair(tweetArr[i],0)));

		}
		else if(i==1){
			markovMMap.insert(make_pair(make_pair("empty",tweetArr[i-1]),make_pair(tweetArr[i],0)));
		
		}
		else{
			markovMMap.insert(make_pair(make_pair("empty","empty"),make_pair(tweetArr[i],0)));
	
		}
		i++;
	}

	multimap<pair<string,string>,pair<string,double>>::iterator iter1;
	multimap<pair<string,string>,pair<string,double>>::iterator iter2;
	
	int countArr[markovMMap.size()];
	int index = 0;
	int totalCount;
	for(iter1 = markovMMap.begin(); iter1 != markovMMap.end(); ++iter1){
		totalCount = 0;
		for(iter2 = markovMMap.begin(); iter2 != markovMMap.end(); ++iter2){
			//if(iter2 != iter1){
				if((iter2->first.first == iter1->first.first) && (iter2->first.second == iter1->first.second)){
          if(iter2->second.first == iter1->second.first){
            iter2->second.second = iter2->second.second +1;

          }
          totalCount = totalCount+1;
				}
        
        
				//iter2->second.second = iter2->second.second + 1;
        //totalCount = totalCount+1;
			//}
			
		}
		countArr[index] = totalCount;
		index = index+1;
	}
	
	index = 0;
	for(iter1 = markovMMap.begin(); iter1 != markovMMap.end(); ++iter1){
    //cout<< countArr[index]<< " ";
		if(iter1->second.second != 0){
			iter1->second.second = (iter1->second.second)/(countArr[index]);	
		}
		index = index+1;
	}	
	
	outFile.open("tweetOut2.txt");	
	
	multimap<pair<string,string>,pair<string,double>>::iterator iter;

  
  
  //dene's attempt
  //for(iter = markovMMap.begin(); iter != markovMMap.end(); ++iter){
    
   // iter->second.first

		//index = index+1;
	//}	


  

  //Mark's Attempt
  //cout << markovMMap.find(pair<string,string> ("Blessed","are"))->second.first;
  //for (pair<pair<string,string>, pair<string,double>> elem : markovMMap){
    //cout << elem.second.first << " " << elem.second.second << endl;
  //}
  int charCount = 0;
  outFile << markovMMap.find(pair<string,string> ("empty","empty"))->second.first << " ";
  charCount += strlen(markovMMap.find(pair<string,string> ("empty","empty"))->second.first) + 1;
  while(charCount<250){
    


    charCount += strlen(iter....);
  }
  //for(iter = markovMMap.begin(); iter != markovMMap.end(); ++iter){
  //  cout << markovMMap.find(pair<string,string> ("Blessed","are"))->second.first;
  //}




  //empty empty

	for(iter = markovMMap.begin(); iter != markovMMap.end(); ++iter){
		outFile << iter->first.first << " " << iter->first.second << " " << iter->second.first << " " << iter->second.second << endl;
	}

	return 0;

}

