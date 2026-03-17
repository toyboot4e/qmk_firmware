{
  # ./keyboards/jeebis/mejiro31/
  description = "A basic flake with a shell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };

  outputs =
    { nixpkgs, ... }:
    let
      systems = nixpkgs.lib.systems.flakeExposed;
      pkgsFor = nixpkgs.lib.genAttrs systems (system: import nixpkgs { inherit system; });
      forEachSystem = f: nixpkgs.lib.genAttrs systems (system: f pkgsFor.${system});
    in
    {
      devShells = forEachSystem (pkgs: {
        default = pkgs.mkShell {
          # buildInputs = [ ];

          packages = with pkgs; [
            qmk
          ];
        };
      });
    };
}
