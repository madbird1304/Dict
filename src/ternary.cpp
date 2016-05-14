#ifndef TERNARY_CPP
#define TERNARY_CPP

void Tree::insert_(Node** root,char *str)
{
	if (!(*root)) *root = new Node (*str);
	if (*str < ((*root) -> c)) insert_( &((*root) -> left) , str); 
	else if (*str > ((*root) -> c))  insert_( &((*root) -> right) , str);
	else {
		if (*(str+1)) insert_( &((*root) -> middle) , str+1 );
		else ((*root) -> eos)++;
	};
}


int Tree::count_(Node *root,char *str)
{
	if (!root) return 0;
	if (*str < root -> c) return count_(root->left,str);
	if (*str > root -> c) return count_(root->right,str);
	if (*(str+1) == '\0') return root -> eos;
	return count_(root->middle,str+1);
}


std::ostream &operator<< (std::ostream &out ,Node *t)
{
	if (!t) return out << "_";
	return out << "( '" << t->c << "' " << (t -> left) << " " << (t -> middle) << " " << (t -> right) << " )";
}

std::ostream &operator<< (std::ostream &out ,Tree t)
{
	return out << t.root_;
}	


void extract(Node* from, std::string str, std::vector<std::pair<std::string,int>> &v)
{
	if (!from) return;
	str += from -> c;
	if (from -> eos) v.push_back(std::pair<std::string,int>(str , from -> eos));
	auto strx = str.substr(1);
	extract(from -> left , strx , v);
	extract(from -> right , strx , v);
	extract(from -> middle , str , v);
}


typedef std::pair<std::string,int> freqp;

std::vector<freqp>  Tree::freqs()
{
	std::vector<freqp> ret;
	extract(root_ , std::string("") , ret);
	std::sort(ret.begin(),ret.end(), [](freqp l,freqp r) { return l.second > r.second; } );
	
	//std::reverse(ret.begin(),ret.end());
	return ret;
}



#endif