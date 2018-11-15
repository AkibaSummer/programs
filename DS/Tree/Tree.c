BiThrNode *nextnode(BiThrNode *p){
    if(p->Rtag)
        return (p->rchild);
    next=p->rchild;
    while(!next->Ltag){
        next=next->lchild;
    }
    return (next);
}


BiThrNode *priornode(BiThrNode *p){
    if(p->Ltag)
        return (p->lchild);
    next=p->lchild;
    while(!next->Rtag){
        next=next->rchild;
    }
    return (next);
}