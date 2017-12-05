  #include "Library.h"

  Library::Library(const char * name)
  {
    SetName(name);
  }

  Library::SetName(const char * name)
  {
    strcpy(m_name, name);
  }

  const char * Library::GetName() const
  {
    return m_name;
  }

  Book * Library::FindOpenSpot()
  {
    Book *m_inventory_pt = m_inventory;
    int i = 0;
    while (i < LIBRARY_N_BOOKS)
    {
      if(!m_inventory_pt->Valid())
        return m_inventory_pt; //found open spot
      ++i;
      ++m_inventory_pt;
    }
    return NULL; //if nothing found
  }

  Book * Library::operator[](const char * title)
  {
    
  }
