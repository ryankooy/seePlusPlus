#include <iostream>

class CWidget;

class CFactory {
  friend class CWidget;
private:
  unsigned int m_uiCount;
public:
  CFactory();
  ~CFactory();
  CWidget* GetWidget();
};

class CWidget {
private:
  CFactory& m_parent;
private:
  CWidget();                          // Disallow default constructor.
  CWidget(const CWidget&);            // Disallow copy constructor.
  CWidget& operator=(const CWidget&); // Disallow assignment operator.
public:
  CWidget(CFactory& parent);
  ~CWidget();
};

// Constructors/destructors.
CFactory::CFactory() : m_uiCount(0) {}
CFactory::~CFactory() {}

// Widget-maker.
CWidget* CFactory::GetWidget()
{
  return new CWidget(*this); // We're its parent.
}

CWidget::CWidget(CFactory& parent) : m_parent(parent)
{
  ++m_parent.m_uiCount;
  std::cout << "Widget spawning. There are now " << m_parent.m_uiCount
            << " widgets instantiated." << std::endl;
}

CWidget::~CWidget()
{
  --m_parent.m_uiCount;
  std::cout << "Widget dying. There are now " << m_parent.m_uiCount
            << " widgets instantiated." << std::endl;
}

int main()
{
  CFactory factory;
  CWidget* pWidget1 = factory.GetWidget();
  CWidget* pWidget2 = factory.GetWidget();
  delete pWidget1;
  CWidget* pWidget3 = factory.GetWidget();
  delete pWidget3;
  delete pWidget2;
  // std::cout << pWidget1 << " " << pWidget2
  //           << " " << pWidget3 << std::endl;
  return 0;
}
