# IN204

## Formatters, Linters and Static Code Analyzers
Installation steps for the hooks used by pre-commit
```ps1
# To install choco
winget install --id=Chocolatey.Chocolatey -e

# To install the hooks
choco install llvm uncrustify cppcheck
pip install cpplint

# To run the hooks
pip install pre-commit
pre-commit install
pre-commit run
```