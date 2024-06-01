{
  description = "A Nix-flake-based Node.js development environment";

  inputs.nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0.1.*.tar.gz";

  outputs = { self, nixpkgs }:
    let
      overlays = [
        (final: prev: rec {
          nodejs = prev.nodejs_latest;
          pnpm = prev.nodePackages.pnpm;
          yarn = (prev.yarn.override { inherit nodejs; });
        })
      ];
      supportedSystems =
        [ "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin" ];
      forEachSupportedSystem = f:
        nixpkgs.lib.genAttrs supportedSystems
        (system: f { pkgs = import nixpkgs { inherit overlays system; }; });
    in {
      devShells = forEachSupportedSystem ({ pkgs }: {
        default = pkgs.mkShell {
          packages = with pkgs; [
            stdenv.cc.cc
            libcs50
            bear
            lldb
            clang
            clang-tools
            nodePackages.nodemon
            nodePackages.typescript-language-server
            node2nix
            nodejs
            pnpm
            yarn
            just
            pm2
            cmake
          ];
          shellHook = ''
            echo "clang `${pkgs.clang}/bin/clang --version`"
            echo "node `${pkgs.nodejs}/bin/node --version`"
              nu
          '';
        };
      });
    };
}
