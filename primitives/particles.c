#include "particles.h"


//? We add at the top of the array
//? We drop the last element
void Ppush(ItemParticle **list, int posX, int posY){
	ItemParticle *new = malloc(sizeof(ItemParticle));
	new->posX = posX;
	new->posY = posY;
	new->next = *list;
	*list = new;
}


void Pdrop(ItemParticle **list){
	ItemParticle *tmp = *list;
	*list = (*list)->next;
	free(tmp);
}


void Pdraw(SDL_Renderer *renderer, ItemParticle **list, int *pCount){
	if ((*list)->next){
		if ((*list)->posX){
			SDL_Rect rect = {(*list)->posX, (*list)->posY, 10, 10};
			SDL_RenderFillRect(renderer, &rect);
		}
		Pdraw(renderer, &((*list)->next), pCount);
		(*list)->posX -= 8;
	} else while ((*pCount) > 20){
		Pdrop(list);
		(*pCount)--;
	}
}