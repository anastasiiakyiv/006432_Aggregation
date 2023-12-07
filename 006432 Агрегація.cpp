/*
  Допишіть код програми, щоб вона без помилок виводила повідомлення про те,
  що працівники продовжуть працювати навіть після того, як відділ де вони працювали раніше, розформовано.
  Підказка: використовуйте std::vector для зберігання працівників у відділі.
*/

#include <iostream>
#include <vector>

class Worker
{
protected:
    std::string name;

public:
    Worker(std::string n) : name(n) {}
    Worker() : Worker("") {}
    
    std::string getName() const
    {
        return name;
    }

    void setName(std::string newName)
    {
        name = newName;
    }
};
class Department
{
protected:
    std::vector<Worker*> workers;

public:
    void add(Worker* worker)
    {
        workers.push_back(worker);
    }

    void disband()
    {
        workers.clear();
    }

    const std::vector<Worker*>& getWorkers() const {
        return workers;
    }
};
int main()
{
    system("chcp 1251>null");

    Worker* w1 = new Worker("Антін");
    Worker* w2 = new Worker("Івасик");
    Worker* w3 = new Worker("Євген");
    Worker* w4 = new Worker("Їржик");
    {
        Department department;
        department.add(w1);
        department.add(w2);
        department.add(w3);
        department.add(w4);

        std::cout << "Працівники у відділі перед розформуванням:" << std::endl;
        for (const auto& worker : department.getWorkers()) {
            std::cout << worker->getName() << std::endl;
        }

        department.disband();
    }

    std::cout << std::endl;
    std::cout << "Працівники після розформування відділу:" << std::endl;
    std::cout << w1->getName() << " досі працює!" << std::endl;
    std::cout << w2->getName() << " досі працює!" << std::endl;
    std::cout << w3->getName() << " досі працює!" << std::endl;
    std::cout << w4->getName() << " досі працює!" << std::endl;
    delete w1;
    delete w2;
    delete w3;
    delete w4;
    return 0;
}
