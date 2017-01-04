void listAll(string path, const Domain* d) // two-parameter overload
{
    vector<Domain*>::const_iterator it;
    
    it = d->subdomains().begin();
    
    if (d->subdomains().size() == 0) {
        cout << path <<endl;
        
    }
    
    for (it = d->subdomains().begin() ; it < d-> subdomains().end(); it++){
        
        if (d->label() != ""){
            listAll((*it)->label() + "." + path, *it);
        }
        else
            listAll((*it)->label() + path, *it);

    }
    
    
}

