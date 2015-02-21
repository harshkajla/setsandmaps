#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
using namespace std ;

class Sequence {
	private :
		map <int , set <int> > m ;
		vector <int> vect ;
	public :
		Sequence(vector <int> const & q) {
			for(int i = 0 ; i < q.size() ; i++)
				m[q[i]].insert(i) ;
			vect = q ;
		}
		void operator()(int i , int x) {
			map <int , set <int> > :: iterator p = m.find(vect[i]) ;
			(p -> second).erase(i) ;
			if((p -> second).empty())
				m.erase(p) ;
			m[x].insert(i) ;
			vect[i] = x ;
		}
		bool is_subsequence(vector <int> & q) {
			if(q.size() == 0)
				return true ;
			map <int , set <int> > :: iterator p = m.find(q[0]) ;
			if(p == m.end())
				return false ;
			
			set <int> :: iterator it = (p -> second).begin() ;
			
			for(int i = 1 ; i < q.size() ; i++) {
				p = m.find(q[i]) ;
				if(p == m.end())
					return false ;
				it = (p -> second).upper_bound(*it) ;
				if(it == (p -> second).end())
					return false ;
			}
			return true ;
		}
} ;
