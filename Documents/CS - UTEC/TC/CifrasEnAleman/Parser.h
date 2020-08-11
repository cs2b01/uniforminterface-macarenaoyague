//
// Created by Macarena Oyague on 2020-02-13.
//

#ifndef CIFRASENALEMAN_PARSER_H
#define CIFRASENALEMAN_PARSER_H

class Parser{
private:
public:
    Parser () = default;
    void evaluateNumber(Scanner scanner)
    {
        if (scanner.getSaveScan()!="false")
            cout<<endl<<"Input aceptado";
        else
            cout<<endl<<"Input rechazado. Intente nuevamente.";
    }
};



#endif //CIFRASENALEMAN_PARSER_H
