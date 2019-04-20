
#include "bintree_eda.h"
template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
	size_t altura() const {
		return altura(this->raiz);
	}
	void properties(int &nodes, int &leaves, int &high){
		nodes = countNodes(this->raiz);
		leaves = countLeaves(this->raiz);
		high = altura();
	}
	// lee un árbol binario de la entrada estándar
	template <typename U>
	bintree_ext<U> leerArbol_ext(U vacio) {
		U raiz;
		std::cin >> raiz;
		if (raiz == vacio) { // es un árbol vacío
			return{};
		}
		else { // leer recursivamente los hijos
			auto iz = leerArbol_ext(vacio);
			auto dr = leerArbol_ext(vacio);
			return{ iz, raiz, dr };
		}
	}

private:
	static size_t altura(Link r) {
		if (r == nullptr) {
			return 0;
		}
		else {
			return 1 + std::max(altura(r->left), altura(r->right));
		}
	}

	int countNodes(Link root){
		if (root ==nullptr) return 0;
		else return 1 + countNodes(root->left) + countNodes(root->right);
	}

	int countLeaves(Link root){
		if (root == nullptr)
			return 0;
		else if (root->right == nullptr &&root->left == nullptr)
			return 1;
		return countLeaves(root->right) + countLeaves(root->left);
	}
};